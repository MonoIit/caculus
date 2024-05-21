#ifndef EDITOR1_H
#define EDITOR1_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>>

QT_BEGIN_NAMESPACE
namespace Ui {
class editor1;
}
QT_END_NAMESPACE

class editor1 : public QMainWindow
{
    Q_OBJECT

public:
    editor1(QWidget *parent = nullptr);
    ~editor1();

private slots:
    void openFile(const QString &filePath);
    void saveFile(const QString &filePath);

    void on_actionOpen_file_triggered();
    void on_actionSave_file_triggered();

    void on_actionFull_Screan_2_triggered();

    void keyPressEvent(QKeyEvent *event);

    void on_actionStatus_Bar_triggered();

    void on_actionDegree_2_triggered();

private:
    Ui::editor1 *ui;
    QLineEdit *lineedit;
    QPushButton *Grad;
};
#endif // EDITOR1_H
