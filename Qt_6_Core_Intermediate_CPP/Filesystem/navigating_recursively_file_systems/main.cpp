#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>


void list(QDir &dir)
{
    qInfo()<<"-------- Listing ---------";

    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Filter::AllEntries | QDir::NoDotAndDotDot,QDir::SortFlag::Name))
    {
        if(fileInfo.isDir())
        {
            qInfo()<<"Directory "<<fileInfo.filePath();
        }

        if(fileInfo.isFile())
        {
            qInfo()<<"File "<<fileInfo.filePath();
        }

        if(fileInfo.isDir())
        {
            QDir child(fileInfo.absoluteFilePath());
            qInfo()<<"Inspecting inside the directory...";

            list(child);
        }
    }
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir = QCoreApplication::applicationDirPath();
    qInfo()<<"The path of the application is: "<<dir.dirName();
    dir.cdUp();

    list(dir);


    return QCoreApplication::exec();
}

/*
In most filesystems, every directory contains two special entries:

- `.` = “this directory”
- `..` = “parent directory”

They are real directory entries (not just a concept), so when you list a folder’s contents, they can appear alongside normal subfolders/files.

### What happens without `NoDotAndDotDot`

Your recursion says: “for every entry that is a directory, call `list(child)`”.

If `.` is included:
1. You are listing directory `A`.
2. You see entry `.` which is also a directory, and it points to **A itself**.
3. You recurse into `A` again.
4. Inside that call you again see `.` → recurse again…
This becomes an infinite recursion: `A -> A -> A -> ...` until you crash (stack overflow) or run out of resources.

If `..` is included:
1. You are listing directory `A`.
2. You see entry `..` which points to **A’s parent**, say `P`.
3. You recurse into `P`.
4. While listing `P`, you see subdirectory `A` again (as a normal entry).
5. Recurse back into `A`, and you’ll see `..` again…
Now you can bounce back and forth forever: `A -> P -> A -> P -> ...` (and also wander upward toward root depending on what else you traverse).

### Why `NoDotAndDotDot` fixes it
`QDir::NoDotAndDotDot` simply tells Qt: “when you build the list of directory entries, omit `.` and `..`”, so your recursion only follows *real subdirectories*, not the self/parent links that create cycles.

### Note
Even with `NoDotAndDotDot`, recursion can still loop if your filesystem contains **symbolic links / junctions** that create cycles (e.g., a symlink inside a folder pointing to one of its ancestors). To be fully safe, you’d also want to detect and skip symlinks or track visited directories.
*/