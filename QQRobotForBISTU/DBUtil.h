#ifndef QQROBOT_DBUTIL_H
#define QQROBOT_DBUTIL_H
#include "public.h"
#include <mysql_connection.h>
#include <driver.h>
#include <statement.h>

#include <resultset.h>
class DBUtil {
private:
	string url;
	string username;
	string password;
	static sql::Driver *driver;
	static sql::Connection *conn;
	void example();
public:
	//连接数据库
	sql::Connection* connect(string url, string username, string password);
	//获取链接
	sql::Connection* getConnection();
	//判断当前是否连接成功
	bool isConnected();
	//切换数据库
	void use(string dbName);
	//关闭数据库
	void close();
	//执行查询sql
	sql::Statement* createStatement();
	sql::PreparedStatement* prepareStatement(string sql);
	bool execute(string sql);
	sql::ResultSet* executeQuery(string sql);
	int executeUpdate(string sql);
	DBUtil();
	~DBUtil();
};

#endif