#ifndef BUFF_H
#define BUFF_H

#include <QString>
#include <QtSql>

class Buff
{
public:
    Buff();
    int ID_PQ;
    QString TextQ;
    QString d1TextQ;
    QString d2TextQ;
//    QString d3TextQ;
    int d1Dash;
    int d2Dash;
//    int d3Dash;
    bool DiedBuff;
    int DiedQ;

    void WriteFromDB()
    {
        if (DiedBuff)
        {
            DiedQ = 1;
        }
        else
        {
            DiedQ = NULL;
        }


        QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE", "SQLITE");
        QSqlQuery query(db);
        db.setDatabaseName("C:/qt_creator/MyProjectQ_2/myproject.db");
        bool ok=db.open();
        if(!ok)
        {
//            throw QDebug("Cannot open database");
        }
        else
        {
            query.prepare("INSERT INTO QuestionState (id, Text, d1_Text, d2_Text, d3_Text, d1_Key, d2_Key, d3_Key, died) VALUES (:idP, :TextP, :d1_TextP, :d2_TextP, :d3_TextP, :d1_KeyP, :d2_KeyP, :d3_KeyP, :diedP)");
                query.bindValue(":idP", ID_PQ);
                query.bindValue(":TextP", TextQ);
                query.bindValue(":d1_TextP", d1TextQ);
                query.bindValue(":d2_TextP", d2TextQ);
                query.bindValue(":d1_KeyP", d1Dash);
                query.bindValue(":d2_KeyP", d2Dash);
                query.bindValue(":diedP", DiedQ);

        }
        query.exec();
        db.close();
    }
};

#endif // BUFF_H
