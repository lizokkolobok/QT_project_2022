#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include <QDialog>

namespace Ui {
class AddRowDialog;
}

class AddRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowDialog(QWidget *parent = nullptr);
    ~AddRowDialog();
    const QList<QVariant>& NewRow();
private:
    Ui::AddRowDialog *ui;
    QList<QVariant> newrow;
private slots:
    void saveRow();
};

#endif // ADDROWDIALOG_H
