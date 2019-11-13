//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>

using namespace std;
const int MAXWIDTH = 1920;
const int MINWIDTH = 320;

QGridLayout* grid = new QGridLayout;

QGridLayout* ReturnGrid(){
    return grid;
}

void LargeLayout(const QRect *r, QList<QLayoutItem *> list_){

    int xLeft = 0, xRight = r->width(), col = 0, resultFlag = 0, resultCol = 0;

    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);
        ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());


            if (label == NULL) {// null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
            }
            else if (label->text() == kHomeLink) {
                label->setGeometry(xLeft, col, r->width() * 0.15, r->height() * 0.1);
                xLeft = xLeft + r->width() * 0.15;
            }
            else if (label->text() == kSearchText){
                label->setGeometry(xLeft+r->width()*0.1, col*0.08, r->width()*0.5, r->height()*0.07);
                xLeft = xLeft+r->width()*0.6;
            }
            else if (label->text() == kSearchButton){
                label->setGeometry(xLeft,col*0.08,r->width()*0.1,r->height()*0.07);
            }
            else if (label->text() == kShoppingBasket) {
                label->setGeometry(xRight - r->width() * 0.07, col, r->width() * 0.07, r->height() * 0.1);
                xRight = xRight - r->width() * 0.07;
            }
            else if (label->text() == kSignIn) {
                label->setGeometry(xRight - r->width() * 0.1, col, r->width() * 0.1, r->height() * 0.1);
                xRight = 0;
                col = r->height()*0.1;
                xLeft = 0;
            }
            else if (label->text() == kBackButton) {
                label->setGeometry(xLeft, col, r->width()*0.075, r->height()*0.07);
                xLeft = xLeft+r->width()*0.15;
            }
            else if (label->text() == kNavTabs){
                label->setGeometry(xLeft, col, r->width()-xLeft, r->height()*0.07);
                col = col + r->height()*0.07;
                xLeft = 0;
            }
            else if (label->text() == kSearchOptions){
                label->setGeometry(xLeft, col, r->width()*0.15, r->height()*0.85-col);
                xLeft = r->width()*0.1;
            }
            else if (label->text() == kSearchResult){
                if (resultFlag == 0){
                    resultCol = r->height()*0.19;
                    resultFlag = 1;
                }
                else{
                    resultCol = resultCol + r->height()*0.2;
                }

                label->setGeometry(r->width()*0.2, resultCol, r->width()*0.6, r->height()*0.18);
            }
            else if (label->text() == kAdvert){
                label->setGeometry(r->width()-r->width()*0.15,col,r->width()*0.15,r->height()*0.85-col);
            }
            else if (label->text() == kSearchBackward){
                label->setGeometry(r->width()*0.4, r->height()*0.783, r->width()*0.1, r->height()*0.05);
            }
            else if (label->text() == kSearchForward){
                label->setGeometry(r->width()*0.5, r->height()*0.783, r->width()*0.1, r->height()*0.05);
            }
            else if (label->text() == kFooter){
                label->setGeometry(0, r->height()*0.85, r->width(), r->height()*0.15);
            }
        }
        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }

    }
}


// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {
    // for all the Widgets added in ResponsiveWindow.cpp
    if (r.width()>r.height()){
        //landscape
        if (r.width()>=MAXWIDTH*0.71){
            //large
            LargeLayout(&r, list_);
        }
        else if (r.width()>=MAXWIDTH*0.70){
            LargeLayout(&r, list_);
        }
    }
    else{
        //portrait
        LargeLayout(&r, list_);
    }

}


// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize(320,320);
}

ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
