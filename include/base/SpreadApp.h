#ifndef SPREADAPP_H
#define SPREADAPP_H

#include "MooseApp.h"

class SpreadApp;

template<>
InputParameters validParams<SpreadApp>();

class SpreadApp : public MooseApp
{
public:
  SpreadApp(InputParameters parameters);
  virtual ~SpreadApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* SPREADAPP_H */
