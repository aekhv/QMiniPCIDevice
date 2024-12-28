#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QMiniPCIDevice.h"
#include <QThread>

#define output(s) ui->plainTextEdit->appendPlainText(s)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->refreshButton, &QPushButton::pressed, this, &MainWindow::refresh);
    connect(ui->getInfoButton, &QPushButton::pressed, this, &MainWindow::getInfo);
    connect(ui->removeButton, &QPushButton::pressed, this, &MainWindow::removeSelectedDevice);
    connect(ui->rescanButton, &QPushButton::pressed, this, &MainWindow::rescanPCIBus);

    refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh()
{
    ui->deviceBox->clear();
    const QStringList devices = QMiniPCIDevice::availableDevices("mini*");
    foreach (const QString dev, devices)
        ui->deviceBox->addItem(dev);
}

void MainWindow::getInfo()
{
    QMiniPCIDevice dev;
    const QString path = ui->deviceBox->currentText();

    output("");

    if (!dev.open(path)) {
        output("Device opening error!");
        return;
    }

    output("*** PCI DEVICE INFO ***\n");

    QMiniPCIDriverVersion ver = dev.driverVersion();
    output(QString("Driver version: %1\n").arg(ver.toString()));

    QMiniPCIDeviceInfo info = dev.deviceInfo();
    output(QString("PCI device location (domain:bus:slot.function): %1")
           .arg(info.location().toString()));
    output(QString("PCI device ID (vendor:device:class:revision): %1")
           .arg(info.id().toString()));
    output(QString("PCI device link speed: %1").arg(info.link().toString()));
}

void MainWindow::removeSelectedDevice()
{
    QMiniPCIDevice dev;
    const QString path = ui->deviceBox->currentText();

    output("");

    if (!dev.open(path)) {
        output("Device opening error!");
        return;
    }

    QMiniPCIDeviceInfo info = dev.deviceInfo();
    QMiniPCIDeviceLocation location = info.location();

    dev.close(); // IMPORTANT!!!

    bool retval = QMiniPCIDevice::removeDevice(location);
    if (retval)
        output("SUCCESS! Selected device can be disconnected.");
    else
        output("FAIL! Do you run this application as sudo user?");
    QThread::msleep(1000);
    refresh();
}

void MainWindow::rescanPCIBus()
{
    output("");
    bool retval = QMiniPCIDevice::rescanPCIBus();
    if (retval)
        output("SUCCESS! Bus rescan completed.");
    else
        output("FAIL! Do you run this application as sudo user?");
    QThread::msleep(1000);
    refresh();
}

