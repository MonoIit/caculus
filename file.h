#ifndef FILE_H
#define FILE_H

#include <QDialog>

namespace Ui {
class file;
}

class file : public QDialog
{
    Q_OBJECT

public:
    explicit file(QWidget *parent = nullptr);
    ~file();

private:
    Ui::file *ui;
signals:
    void filePath(const QString &str);
private slots:
    void okClicked();
};

#endif // FILE_H
