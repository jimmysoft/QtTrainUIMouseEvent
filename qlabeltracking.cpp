#include "qlabeltracking.h"
#include "iostream"
#include <QMouseEvent>

QLabelTracking::QLabelTracking(QWidget *parent) :
    QLabel(parent)
{
    blisterInfoDialog = (BlisterInfoDialog*)parent;

    this->setMouseTracking(true);

}

void QLabelTracking::mousePressEvent(QMouseEvent *ev)
{
    this->setMouseTracking(false);
}

void QLabelTracking::mouseMoveEvent(QMouseEvent *ev)
{
    QCursor cursor;
    int x = ev->x();
    int y = ev->y();
    if(x>20&&y>20&&x<240&&y<180&&this->hasMouseTracking())
    {

        if(x>blisterInfoDialog->getBlisterLabelWidth()+20-3&&x<blisterInfoDialog->getBlisterLabelWidth()+20+3
                &&y>blisterInfoDialog->getBlisterLabelHeight()+20-3&&y<blisterInfoDialog->getBlisterLabelHeight()+20+3)
        {
            cursor.setShape(Qt::SizeFDiagCursor);
            this->setCursor(cursor);
            type = 0;

        }
        else if(x>blisterInfoDialog->getBlisterLabelWidth()+20-3&&x<blisterInfoDialog->getBlisterLabelWidth()+20+3)
        {
            cursor.setShape(Qt::SizeHorCursor);
            this->setCursor(cursor);
            type = 1;

        }
        else if(y>blisterInfoDialog->getBlisterLabelHeight()+20-3&&y<blisterInfoDialog->getBlisterLabelHeight()+20+3)
        {
            cursor.setShape(Qt::SizeVerCursor);
            this->setCursor(cursor);
            type = 2;

        }
        else
        {
            cursor.setShape(Qt::ArrowCursor);
            this->setCursor(cursor);
            this->setMouseTracking(true);
        }

    }
    else if(x>20&&y>20&&x<240&&y<180&&!this->hasMouseTracking())
    {
        int width;
        int height;
        switch (type) {
        case 0:
            width = x-20;
            height = y-20;
            blisterInfoDialog->changeBlisterSize(width, height);
            blisterInfoDialog->changeSpinValue(width, height);
            break;
        case 1:
            width = x-20;
            height = blisterInfoDialog->getBlisterLabelHeight();
            blisterInfoDialog->changeBlisterSize(width, height);
            blisterInfoDialog->changeSpinValue(width, height);
            break;
        case 2:
            width = blisterInfoDialog->getBlisterLabelWidth();
            height = y-20;
            blisterInfoDialog->changeBlisterSize(width, height);
            blisterInfoDialog->changeSpinValue(width, height);
            break;
        }
    }


}

void QLabelTracking::mouseReleaseEvent(QMouseEvent *ev)
{
    QCursor cursor;
    cursor.setShape(Qt::ArrowCursor);
    this->setCursor(cursor);
    this->setMouseTracking(true);
}

