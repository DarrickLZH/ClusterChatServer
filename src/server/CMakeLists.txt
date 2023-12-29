# 定义了一个SRC_LIST变量，包含了该目录下所有的源文件
aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_LIST)
aux_source_directory(./model MD_LIST)
aux_source_directory(./redis REDIS_LIST)

# 指定生成可执行文件
add_executable(ChatServer ${DB_LIST} ${SRC_LIST} ${MD_LIST} ${REDIS_LIST})
# 指定可执行文件链接时所需的库文件
target_link_libraries(ChatServer muduo_net muduo_base mysqlclient hiredis pthread)