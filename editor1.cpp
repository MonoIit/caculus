#include "editor1.h"
#include "ui_editor1.h"
#include "file.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QtGui>

editor1::editor1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::editor1)
{
    ui->setupUi(this);
    Grad = new QPushButton();
    ui->statusbar->showMessage("ok");
}

editor1::~editor1()
{
    delete ui;
}

void editor1::on_actionOpen_file_triggered()
{
    file *wnd = new file(this);
    wnd->show();

    connect(wnd, SIGNAL(filePath(QString)), this, SLOT(openFile(QString)));
}


void editor1::on_actionSave_file_triggered()
{
    file *wnd = new file(this);
    wnd->show();

    connect(wnd, SIGNAL(filePath(QString)), this, SLOT(saveFile(QString)));
}

void editor1::openFile(const QString &filePath)
{
    QFile mFile(filePath);
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Error open file");
        ui->statusbar->showMessage("Error open file");
        return;
    }
    QTextStream stream(&mFile);
    QString buffer = stream.readAll(); /*readline*/
    ui->textBrowser->setText(buffer);
    ui->statusbar->showMessage("Read file: " + filePath);

    mFile.flush();
    mFile.close();
}

void editor1::saveFile(const QString &filePath)
{
    QFile mFile(filePath);
    if (!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Error save file");
        ui->statusbar->showMessage("Error save file");
        return;
    }
    QTextStream stream(&mFile);
    stream << ui->textBrowser->toPlainText();
    ui->statusbar->showMessage("Write to file: " + filePath);

    mFile.flush();
    mFile.close();
}

void editor1::on_actionFull_Screan_2_triggered()
{
    if(this->isFullScreen()){
        this->showNormal();
    } else {
        this->showFullScreen();
    }
}

void editor1::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        QString string = ui->lineEdit->text();
        if (!string.isEmpty())
        {
            QString value = 0;
            ui->textBrowser->QTextBrowser::append(string);
            /*ui->textBrowser->QTextBrowser::append(string);*/
            ui->textBrowser->QTextBrowser::append(value);
            ui->lineEdit->clear();
        }
    }
}


void editor1::on_actionStatus_Bar_triggered()
{
    if (!ui->toolBar->isHidden())
    {
        ui->toolBar->setVisible(false);
    } else {
        ui->toolBar->setVisible(true);
    }
}


void editor1::on_actionDegree_2_triggered()
{
    QString name = ui->actionDegree_2->text();
    if (name == "Radian") {
        QString name = "Degree";
        ui->actionDegree_2->setText(name);
    } else {
        QString name = "Radian";
        ui->actionDegree_2->setText(name);
    }
}

