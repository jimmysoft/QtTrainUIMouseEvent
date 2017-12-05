#ifndef QLABELTRACKING_H
#define QLABELTRACKING_H

#include <QLabel>
#include <QWidget>
#include <blisterinfodialog.h>

class QLabelTracking : public QLabel
{
    Q_OBJECT
public:
    explicit QLabelTracking(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent* ev);
    void mouseMoveEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);

    int type;

    BlisterInfoDialog* blisterInfoDialog;

signals:

public slots:

};

#endif // QLABELTRACKING_H
