# FTP Server Implementation

## Usage
### How To Compile
For compilation use the following command in __ftpclient/__ and __ftpserver/__ directories
```bash
make
```
* Note: Ensure you have __g++__ on your computer
### How To Run
#### Server
```bash
./ftpserver.out config.json
```
#### Client
```bash
./ftpclient.out
```
## Supported Commands
| Template            | Example          | Description                             |
| ------------------- | ---------------- | --------------------------------------- |
| user "username"     | user Ali         | enter username for authentication       |
| pass "password"     | pass 1234        | enter password for authentication       |
| pwd                 | pwd              | get current directory path              |
| mkd "directory"     | mkd temp         | create new directory with provided name |
| dele -f "filename"  | dele -f tempf    | delete file with provided name          |
| dele -d "dirpath"   | dele -d tempd    | delete directory with provided name     |
| ls                  | ls               | get files and directories in pwd        |
| cwd "new path"      | cwd new_path     | change path to new_path                 |
| rename "from" "to"  | rename old new   | rename file from old name to new name   |
| retr "filename"     | retr config.json | download file                           |
| help                | help             | get help message for commands           |
| quit                | quit             | logout from account                     |

