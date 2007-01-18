/*
 * =====================================================================================
 *        Filename:  basic_algos.h
 *     Description: 
 *         Created:  26/11/2006 17:42:41 PM CET
 *          Author:  jmisutka ()
 * =====================================================================================
 */

#ifndef _BASIC_ALGOS_H_
#define _BASIC_ALGOS_H_ 


//============================================
namespace _JM_NAMESPACE {
//============================================

#undef max
#undef min
using std::max;
using std::min;


//=====================================================================================
// Standard min / max functions
//=====================================================================================

/** Min of four items. */
template<typename T>
inline T min (T a, T b, T c, T d)
	{ return std::min (std::min(a,b), std::min(c,d)); }

/** Max of four items. */
template<typename T>
inline T max (T a, T b, T c, T d)
	{ return std::max (std::max(a,b), std::max(c,d)); }

//============================================
} // namespace _JM_NAMESPACE
//============================================


#endif // _BASIC_ALGOS_H_ 
