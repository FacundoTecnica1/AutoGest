#ifndef ADMIN_H
#define ADMIN_H
#include <QString>

class Admin {
private:
    int idAdmin;
    QString user;
    QString password;

public:
    Admin();
    Admin(int idAdmin, QString user, QString password);

    int getIdAdmin() const;
    void setIdAdmin(int value);

    QString getUser() const;
    void setUser(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);
};

#endif // ADMIN_H