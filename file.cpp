#include "file.h"
#include "ui_file.h"
#include <QPushButton>

file::file(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::file)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), SLOT(okClicked()));
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), SLOT(close()));
}

void file::okClicked(){
    emit filePath(ui->lineEdit->text());
    close();
}

file::~file()
{
    delete ui;
}
