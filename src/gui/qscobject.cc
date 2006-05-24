/** @file
 QSCObject -> base class of all QObject wrappers used in scripting<br>
 Export some functions to scripting.<br>
 See doc/user/scripting.xml or kernel documentation for more informations about these functions<br>
 @author Martin Petricek
*/

#include <utils/debug.h>
#include "qscobject.h"
#include <qstring.h>
#include "base.h"
#include "util.h"

namespace gui {

//todo: add garbage collection if needed

/**
 Construct wrapper with given CObject
 @param _typeName Name of this objects type
 @param _base scripting base for this object
 */
QSCObject::QSCObject(QString _typeName, Base* _base) {
 typeName=_typeName;
 base=_base;
 guiPrintDbg(debug::DBG_DBG,"adding QSCObject "<< typeName);
//todo: add to garbage collector. Garbage collector is one for each editor window.
 if (base) base->addGC(this);
}

/** Copy constructor */
QSCObject::QSCObject(QSCObject &source) : QObject() {
 typeName=source.typeName;
 base=source.base;
 guiPrintDbg(debug::DBG_DBG,"adding QSCObject (copy) " << typeName);
 if (base) base->addGC(this);
}

/** destructor */
QSCObject::~QSCObject() {
 guiPrintDbg(debug::DBG_DBG,"removing QSCObject" << typeName);
//todo: remove from  garbage collector. After returning from scripting, GC should be run ...
 if (base) base->removeGC(this);
}

/**
 \copydoc Base::treeNeedReload
 This will call Base::treeNeedReload, if base is set for this object.
*/
void QSCObject::treeNeedReload() {
 if (base) base->treeNeedReload();
}

/** Return name of this object's type
  @return name of this object's type
*/
QString QSCObject::type() {
 return typeName;
}
/** Deletes itself */
void QSCObject::deleteSelf() {
 delete this;
}

} // namespace gui
