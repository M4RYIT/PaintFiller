set PRJ_PATH=%~dp0
set BIN_PATH=%PRJ_PATH%bin\
set APP_PATH=%PRJ_PATH%filler_app\
set CORE_PATH=%PRJ_PATH%filler_core\

clang -I%APP_PATH%include -I%CORE_PATH%include -o %BIN_PATH%app.exe %APP_PATH%src\*.c -L %BIN_PATH% -l filler_core