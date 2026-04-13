#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
    QString m_message;

public:
    explicit Test(QObject *parent = nullptr);

    Q_PROPERTY(QString messageProperty READ message WRITE setMessage NOTIFY messageChanged)

    QString message() const;
    void setMessage(const QString &newMessage);

signals:
    void messageChanged(QString message);
};

#endif // TEST_H
