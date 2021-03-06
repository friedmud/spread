#include "SpreadApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<SpreadApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

SpreadApp::SpreadApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  SpreadApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  SpreadApp::associateSyntax(_syntax, _action_factory);
}

SpreadApp::~SpreadApp()
{
}

// External entry point for dynamic application loading
extern "C" void SpreadApp__registerApps() { SpreadApp::registerApps(); }
void
SpreadApp::registerApps()
{
  registerApp(SpreadApp);
}

// External entry point for dynamic object registration
extern "C" void SpreadApp__registerObjects(Factory & factory) { SpreadApp::registerObjects(factory); }
void
SpreadApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void SpreadApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { SpreadApp::associateSyntax(syntax, action_factory); }
void
SpreadApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
