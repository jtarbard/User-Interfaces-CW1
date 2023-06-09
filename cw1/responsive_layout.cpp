//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>

using namespace std;

void SmallLayout(const QRect *r, QList<QLayoutItem *> list_) {
    /*
     * Small Layout - Handles label placement for
     * small screens < (0.45 * 1920px).
     */
    int resultFlag = 0, resultCol = 0;

    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);
        ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) { // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
            }
            else if (label->text() == kHomeLink)  { //home button
                label->setGeometry(0, 0, r->width() * 0.25, r->height() * 0.1);
            }
            else if (label->text() == kShoppingBasket) { //shopping basket
                label->setGeometry( r->width()*0.8, 0, r->width()*0.2, r->height() * 0.1);
            }
            else if (label->text() == kSignIn) { //sign in button
                label->setGeometry(r->width()*0.6, 0, r->width()*0.2, r->height() * 0.1);
            }
            else if (label->text() == kBackButton) { //hidden: navigation back button
                label->setGeometry(-1,-1,0,0);
            }
            else if (label->text() == kNavTabs){ //hidden: navigation tree
                label->setGeometry(-1,-1,0,0);
            }
            else if (label->text() == kSearchText){ //search bar
                label->setGeometry(r->width() * 0.05, r->height()*0.115, r->width()*0.75, r->height()*0.1);
            }
            else if (label->text() == kSearchButton){ //search button
                label->setGeometry(r->width()*0.8,r->height()*0.115,r->width()*0.15,r->height()*0.1);
            }
            else if (label->text() == kSearchOptions){ //hidden: search options
                label->setGeometry(-1,-1,0,0);
            }
            else if (label->text() == kSearchResult || label->text() == kAdvert){ //search results and adverts
                if (resultFlag == 0){
                    resultCol = r->height()*0.23;
                    resultFlag = 1;
                }
                else{ //non-first, iterable item
                    resultCol = resultCol + r->height()*0.165;
                }
                if(resultCol + r->height()*0.21 < r->height()) { //if item fits on page place
                    label->setGeometry(r->width() * 0.05, resultCol, r->width() * 0.90, r->height() * 0.15);
                }
                else{ //item does not fit place off of page
                    label->setGeometry(-1,-1,0,0);
                }
            }
            else if (label->text() == kSearchBackward){ //search page backward button
                label->setGeometry(r->width()*0.05, r->height()*0.9, r->width()*0.4, r->height()*0.07);
            }
            else if (label->text() == kSearchForward){ //search page forward button
                label->setGeometry(r->width()*0.55, r->height()*0.9, r->width()*0.4, r->height()*0.07);
            }
            else if (label->text() == kFooter){ //hidden: footer
                label->setGeometry(-1, -1, 0, 0);
            }
        }
        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

void MediumLayout(const QRect *r, QList<QLayoutItem *> list_) {
    /*
     * Medium Layout - Handles label placement for
     * medium screens >= (0.45 * 1920px).
     */
    int resultFlag = 0, resultCol = 0;

    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);
        ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) {// null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
            }
            else if (label->text() == kHomeLink) { //home button
                label->setGeometry(0, 0, r->width() * 0.2, r->height() * 0.1);
            }
            else if (label->text() == kShoppingBasket) { //shopping basket button
                label->setGeometry( r->width()*0.9, 0, r->width()*0.1, r->height() * 0.1);
            }
            else if (label->text() == kSignIn) { //sign in button
                label->setGeometry(r->width()*0.8, 0, r->width()*0.1, r->height() * 0.1);
            }
            else if (label->text() == kBackButton) { //back button
                label->setGeometry(0, r->height()*0.1, r->width()*0.2, r->height()*0.1);
            }
            else if (label->text() == kNavTabs){ //navigation tree
                label->setGeometry(r->width()*0.2, r->height()*0.1, r->width()*0.85, r->height()*0.1);
            }
            else if (label->text() == kSearchText){ //search bar
                label->setGeometry(r->width() * 0.25, r->height()*0.215, r->width()*0.55, r->height()*0.07);
            }
            else if (label->text() == kSearchButton){ //search button
                label->setGeometry(r->width()*0.8,r->height()*0.215,r->width()*0.15,r->height()*0.07);
            }
            else if (label->text() == kSearchOptions){ //search options
                label->setGeometry(0, r->height()*0.2, r->width()*0.2, r->height()*0.8);
            }
            else if (label->text() == kSearchResult || label->text() == kAdvert){ //search results and adverts
                if (resultFlag == 0){ //if first item
                    resultCol = r->height()*0.3;
                    resultFlag = 1;
                }
                else{ //non-first, iterable item
                    resultCol = resultCol + r->height()*0.2;
                }
                if(resultCol + r->height()*0.25 < r->height()) { //if item fits on page place
                    label->setGeometry(r->width() * 0.25, resultCol, r->width() * 0.70, r->height() * 0.18);
                }
                else{ //item does not fit place off of page
                    label->setGeometry(-1,-1,0,0);
                }
            }
            else if (label->text() == kSearchBackward){ //search page backward button
                label->setGeometry(r->width()*0.5, r->height()*0.9, r->width()*0.1, r->height()*0.08);
            }
            else if (label->text() == kSearchForward){ //search page forward button
                label->setGeometry(r->width()*0.6, r->height()*0.9, r->width()*0.1, r->height()*0.08);
            }
            else if (label->text() == kFooter){ //hidden: footer
                label->setGeometry(-1, -1, 0, 0);
            }
        }
        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

void LargeLayout(const QRect *r, QList<QLayoutItem *> list_){
    /*
     * Large Layout - Handles label placement for
     * large screens >= (0.75 * 1920px).
     */
    int resultFlag = 0, resultCol = 0;

    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);
        ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) {// null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
            }
            else if (label->text() == kHomeLink) { //home button
                label->setGeometry(0, 0, r->width() * 0.15, r->height() * 0.1);
            }
            else if (label->text() == kSearchText){ //search bar
                label->setGeometry(r->width() * 0.2, r->height()*0.015, r->width()*0.5, r->height()*0.07);
            }
            else if (label->text() == kSearchButton){ //search button
                label->setGeometry(r->width()*0.7,r->height()*0.015,r->width()*0.1,r->height()*0.07);
            }
            else if (label->text() == kShoppingBasket) { //shopping basket
                label->setGeometry( r->width()*0.925, 0, r->width()*0.075, r->height() * 0.1);
            }
            else if (label->text() == kSignIn) { //sign in button
                label->setGeometry(r->width()*0.85, 0, r->width()*0.075, r->height() * 0.1);
            }
            else if (label->text() == kBackButton) { //navigation back button
                label->setGeometry(0, r->height()*0.1, r->width()*0.075, r->height()*0.07);
            }
            else if (label->text() == kNavTabs){ //navigation tree
                label->setGeometry(r->width()*0.15, r->height()*0.1, r->width()*0.85, r->height()*0.07);
            }
            else if (label->text() == kSearchOptions){ //search options
                label->setGeometry(0, r->height()*0.17, r->width()*0.15, r->height()*0.68);
            }
            else if (label->text() == kSearchResult){ //search results
                if (resultFlag == 0){ //if first result
                    resultCol = r->height()*0.19;
                    resultFlag = 1;
                }
                else{ //non-first, iterable result
                    resultCol = resultCol + r->height()*0.2;
                }
                if(resultCol + r->height()*0.20 < r->height()) { //if item fits on page place
                    label->setGeometry(r->width() * 0.20, resultCol, r->width() * 0.6, r->height() * 0.18);
                }
                else{ //item does not fit place off of page
                    label->setGeometry(-1,-1,0,0);
                }
            }
            else if (label->text() == kAdvert){  //advert
                label->setGeometry(r->width()*0.85,r->height()*0.17,r->width()*0.15,r->height()*0.68);
            }
            else if (label->text() == kSearchBackward){ //search page backward button
                label->setGeometry(r->width()*0.4, r->height()*0.783, r->width()*0.1, r->height()*0.05);
            }
            else if (label->text() == kSearchForward){ //search page forward button
                label->setGeometry(r->width()*0.5, r->height()*0.783, r->width()*0.1, r->height()*0.05);
            }
            else if (label->text() == kFooter){ //footer
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
    //Large layout
    if (r.width()>=1920*0.75){
        LargeLayout(&r, list_);
    }
    //Medium layout
    else if (r.width()>=1920*0.45){
        MediumLayout(&r, list_);
    }
    //Small layout
    else{
        SmallLayout(&r, list_);
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
