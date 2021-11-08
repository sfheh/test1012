#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test1012.h"
#include <mysql.h>
#include <iostream>
#include <ctime>
#include <string>
#include <QMessageBox> 
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QListView>
#include <QStringList>
#include <QTableView>
#include <QStandardItemModel>
#include <QListWidget>


using namespace std;

class test1012 : public QMainWindow
{
    Q_OBJECT

public:
    test1012(QWidget *parent = Q_NULLPTR);

//    string name[10] = {};     // 이렇게 안하고 string name[10];  이것만 하면....+= 등으로 뭔가를 넣을 수 없다요...벡터가 아니라고...ㅠ
//    int price[10] = {};
//    int quantity[10] = {};
//    //int p_q[10];
//    int resource[17] = {};
//
//    // 현재 날짜, 현재 시간
//    string currentDate() {
//        time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
//        struct tm  tstruct;
//        char       buf[30];
//        tstruct = *localtime(&now);
//        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct); // YYYY-MM-DD 형태의 스트링
//
//        return buf;
//    }
//    string currenttime() {
//        time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
//        struct tm  tstruct;
//        char       buf[30];
//        tstruct = *localtime(&now);
//        strftime(buf, sizeof(buf), "%X", &tstruct); // HH:mm:ss 형태의 스트링
//
//        return buf;
//    }
    int menuNumber[100] = {};     // menu number <- selecting in db
    string menuName[100] = {};    // menu name  <- selecting in db
    int menuPrice[100] = {};      // menu price <- selecting in db
    //string menu_p[100] = {};      // menu price  -> inserting in db
    string order_na[100] = {};    // order menu name -> inserting in db
    int orderPrice[100] = {};     // order menu price
    string order_p[100] = {};     // order menu price -> inserting in db
    int orderQuantity[100] = {};  // order menu quantity
    string order_q[100] = {};     // order menu quantity -> inserting in db

    int orderNumber[100] = {};    // order number <- selecting in db
    string order_num[100] = {};   // order number -> inserting in db  

    int menuSumprice[100] = {};   // ui 출력용 주문 메뉴 단가 * 수량 
    int menuPayment[100] = {};    // ui 출력용 주문 총액 

    string currentDate() {  // 현재 날짜
        time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
        struct tm  tstruct;
        char       buf[30];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct); // YYYY-MM-DD 형태의 스트링

        return buf;
    }
    string currenttime() {  //현재 시간
        time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
        struct tm  tstruct;
        char       buf[30];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%X", &tstruct); // HH:mm:ss 형태의 스트링

        return buf;
    }
    int resourceCquantity[17] = {};  // food resource cquantity <- selecting in db
    int resourceTpcs[17] = {};       // food resource tpcs <- selecting in db
    int resourceTquantity[17] = {};  // food resource tquantity <-selecting in db

    int orderTquantity[17] = {};     // order resource tquantity : calculation
    int calculateTquantity[17] = {}; // tquantity = resourceTquantity[i] - orderTquantity[i] 
    string calculate_tq[17] = {};    // tquantity -> updating in db
    int calculateTpcs[17] = {};      // tpcs= (resourceTquantity[i]-orderTquantity[i])/resourceCquantity[i]
    string calculate_tp[17] = {};    // tpcs <- updating in db

//private slots:
//    void Button1();

private:
    Ui::test1012Class ui;
};
