/**********************************************************************
  Optimizer - Generic optimizer interface

  Copyright (C) 2010 by David C. Lonie

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 ***********************************************************************/

#include <xtalopt/optimizers/xtaloptoptimizer.h>
#include <xtalopt/structures/xtal.h>
#include <xtalopt/xtalopt.h>

#include <globalsearch/optbase.h>

#include <QtCore/QFile>

#include <openbabel/obconversion.h>
#include <openbabel/mol.h>

using namespace std;
using namespace OpenBabel;
using namespace Eigen;

namespace XtalOpt {

  XtalOptOptimizer::XtalOptOptimizer(OptBase *parent, const QString &filename) :
    Optimizer(parent)
  {
  }

  XtalOptOptimizer::~XtalOptOptimizer()
  {
  }

  bool XtalOptOptimizer::read(Structure *structure,
                              const QString & filename) {

    if (!Optimizer::read(structure, filename)) {
      return false;
    }

    Xtal *xtal = qobject_cast<Xtal*>(structure);
    XtalOpt *xtalopt = qobject_cast<XtalOpt*>(m_opt);

    xtal->wrapAtomsToCell();
    xtal->findSpaceGroup(xtalopt->tol_spg);
    return true;
  }

} // end namespace avogadro

//#include "xtaloptoptimizer.moc"
