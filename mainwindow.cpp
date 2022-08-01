#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_41_clicked()
{
    QString curPath=QDir::currentPath();
    QString fileName=QFileDialog::getOpenFileName(this,"",curPath,"(*.*)");
    ui->editFile->setText(fileName);
}

void MainWindow::on_pushButton_45_clicked()
{
    QString curPath=QDir::currentPath();
    QString fileName=QFileDialog::getExistingDirectory(this,"",curPath);
    ui->editDir->setText(fileName);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_pushButton_clicked()
{

    getBtnInfo(sender());
    ui->plainTextEdit->appendPlainText(QCoreApplication::applicationDirPath());
}

void MainWindow::getBtnInfo(QObject *btn)
{
    QPushButton *button=static_cast<QPushButton*>(btn);
    ui->plainTextEdit->appendPlainText(button->text());
    ui->plainTextEdit->appendPlainText(button->toolTip());
}

void MainWindow::on_pushButton_48_clicked()
{
    getBtnInfo(sender());
    QString sours=ui->editFile->text();
    QFileInfo info(sours);
    info.baseName();
    QString dest=info.path()+"/"+info.fileName()+"-副本"+info.suffix();
    QFile::copy(sours,dest);
    ui->plainTextEdit->appendPlainText("源文件："+sours);
    ui->plainTextEdit->appendPlainText("副本："+dest+"\n");
}

void MainWindow::on_pushButton_20_clicked()
{
    getBtnInfo(sender());
    QDir dir(ui->editDir->text());
    if(dir.mkdir("newDir"))
        ui->plainTextEdit->appendPlainText("创建成功");
    else
        ui->plainTextEdit->appendPlainText("创建失败");

}
