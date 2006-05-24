#ifndef __QSPDFOPERATOR_H__
#define __QSPDFOPERATOR_H__

#include <qstring.h>
#include <qobject.h>
#include <pdfoperators.h>
#include "qscobject.h"

namespace gui {

class Base;

using namespace pdfobjects;

/*= This type of object represents pdf operator in content stream */
class QSPdfOperator : public QSCObject {
 Q_OBJECT
public:
 QSPdfOperator(boost::shared_ptr<PdfOperator> _cs,Base *_base);
 virtual ~QSPdfOperator();
 boost::shared_ptr<PdfOperator> get();
public slots:
 /*- Return text representation of this pdf operator */
 QString getText();
 /*- Return name of this pdf operator */
 QString getName();
 /*-
  Remove this PDF operator from its ContentStream.
  After calling this function, this object became invalid and must not be used further
 */
 void remove();
 /*-
  Returns child operator with given number from this operator
  Use data fetched by loadChilds method, if it wasn't called, it is called before returning the child
 */
 QSPdfOperator* child(int childNumber);
 /*-
  Returns number of child operators under this pdf operator
  Use data fetched by loadChilds method, if it wasn't called, it is called before returning the count
 */
 int childCount();
 /*-
  Get all child operators under this operator and store them.
  Get the operators with child and childCount functions.
  Usually it is not necessary to call this method, as these funtions will call
  it automatically on first need, but you may call it explicitly to reload the
  list of child operators stored in this object
 */
 void loadChilds();
 /*-
  Returns parameter with given number from this operator
  Use data fetched by loadParams method, if it wasn't called, it is called before returning the parameter
 */
 QSCObject* param(int paramNumber);
 /*-
  Returns number of parameters for this pdf operator
  Use data fetched by loadParams method, if it wasn't called, it is called before returning the count
 */
 int paramCount();
 /*-
  Get all parameters (operands) under this operator and store them.
  Get the operators with param and paramCount functions.
  Usually it is not necessary to call this method, as these funtions will call
  it automatically on first need, but you may call it explicitly to reload the
  list of parameters stored in this object
 */
 void loadParams();
private:
 /** Object held in class*/
 boost::shared_ptr<PdfOperator> obj;
 /** Vector with child operators */
 std::vector<boost::shared_ptr<PdfOperator> > childs;
 /** Number of childs in vector. -1 mean no childs yet parsed */
 int numChilds;
 /** Vector with operator parameters */
 std::vector<boost::shared_ptr<IProperty> > params;
 /** Number of parameters in vector. -1 mean no parameters yet parsed */
 int numParams;
};

} // namespace gui

#endif
