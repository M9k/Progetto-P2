#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <QLabel>
#include <QStatusBar>
#include <QString>


class Status_bar : public QStatusBar
{
    Q_OBJECT

public:
    Status_bar(QString nome, QWidget* parent = 0);

public slots:
    void changeStatus(QString);

private:
    QWidget* contenitore;
    QLabel* welcome;
    QLabel* status;
};

#endif
