#ifndef __TREEITEMREF_H__
#define __TREEITEMREF_H__

#include <iproperty.h>
#include <qlistview.h>
#include "treeitem.h"
class QString;

namespace gui {

using namespace pdfobjects;

class TreeData;
class TreeWindow;

class TreeItemObserver;//internal class (observer)

class TreeItemRef : public TreeItem {
public:
 TreeItemRef(TreeData *_data,QListView *parent,IProperty *pdfObj,const QString name=QString::null,QListViewItem *after=NULL);
 TreeItemRef(TreeData *_data,QListViewItem *parent,IProperty *pdfObj,const QString name=QString::null,QListViewItem *after=NULL);
 virtual ~TreeItemRef();
 QString getRef();
 virtual void setOpen(bool open);
 void unOpen();
 bool isComplete();
 //From TreeItemAbstract interface
 virtual ChildType getChildType(const QString &name);
 virtual TreeItemAbstract* createChild(const QString &name,ChildType typ,QListViewItem *after=NULL);
 virtual QStringList getChildNames();
 virtual void reloadSelf();
protected:
 void addData();
private:
 TreeItem* parentCheck();
 /** If childs of this items are yet unknown and to be parsed/added */
 bool complete;
 /** If this item contains a CRef, this string contain reference target in text form */
 QString selfRef;
};

} // namespace gui

#endif
