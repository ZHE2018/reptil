#include "reptile.h"
#include <QDebug>

reptile::reptile()
{
    qDebug()<<"reptile init";
}

reptile::~reptile()
{

}

QUrl reptile::captureToUrl(const QString &line, const QUrl &currenturl)
{
    QUrl url;
    QString s;
    int b=-1,e=-1,i=0;
    for(auto ptr=line.begin();ptr!=line.end();++ptr,++i)
    {
        if(*ptr==QChar('"'))
        {
            if(b==-1)
            {
                b=i;
            }
            else if(e==-1)
            {
                e=i;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(b>=0&&e==-1)
            {
                s+=(*ptr);
            }
        }
    }
    s.replace(QString("\""),QString(""));



    s=currenturl.url().section(QString("/"),0,2)+s;
    url.setUrl(s);
    return url;
}

void reptile::getNextUrl(const QString &text, QUrl &currentUrl)
{
    QString str=currentUrl.toString();
    QString number=str.section(QString("-"),2,2).section(QString("."),0,0);
    number=QString::number(number.toInt()+1);
    if(number.toInt()>300)
    {
        currentUrl.clear();
        return;
    }
    str=str.section(QString("-"),0,1)+QString("-")+number+QString(".html");
    currentUrl.setUrl(str);
}

