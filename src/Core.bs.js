// Generated by BUCKLESCRIPT VERSION 2.2.2, PLEASE EDIT WITH CARE
'use strict';

var Js_boolean = require("bs-platform/lib/js/js_boolean.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");
var Action = require("@devexpress/dx-react-core/Action");
var Getter = require("@devexpress/dx-react-core/Getter");
var Plugin = require("@devexpress/dx-react-core/Plugin");
var Template = require("@devexpress/dx-react-core/Template");
var Draggable = require("@devexpress/dx-react-core/Draggable");
var DragSource = require("@devexpress/dx-react-core/DragSource");
var DropTarget = require("@devexpress/dx-react-core/DropTarget");
var PluginHost = require("@devexpress/dx-react-core/PluginHost");
var DragDropProvider = require("@devexpress/dx-react-core/DragDropProvider");
var TemplateConnector = require("@devexpress/dx-react-core/TemplateConnector");
var TemplatePlaceholder = require("@devexpress/dx-react-core/TemplatePlaceholder");

function unwrapValue(param) {
  var variant = param[0];
  if (variant >= 758940238) {
    if (variant !== 770676513) {
      if (variant >= 1034997432) {
        throw [
              Caml_builtin_exceptions.assert_failure,
              [
                "Core.re",
                21,
                21
              ]
            ];
      } else {
        return param[1];
      }
    } else {
      throw [
            Caml_builtin_exceptions.assert_failure,
            [
              "Core.re",
              20,
              16
            ]
          ];
    }
  } else if (variant !== -908856609) {
    if (variant >= 737456202) {
      return Js_boolean.to_js_boolean(param[1]);
    } else {
      return param[1];
    }
  } else {
    throw [
          Caml_builtin_exceptions.assert_failure,
          [
            "Core.re",
            19,
            18
          ]
        ];
  }
}

function make(name, action, children) {
  return ReasonReact.wrapJsForReason(Action.default, {
              name: name,
              action: action
            }, children);
}

var Action$1 = /* module */[/* make */make];

function make$1(onChange, children) {
  var tmp = { };
  if (onChange) {
    tmp.onChange = onChange[0];
  }
  return ReasonReact.wrapJsForReason(DragDropProvider.default, tmp, children);
}

var DragDropProvider$1 = /* module */[/* make */make$1];

function make$2(payload, onStart, onUpdate, onEnd, children) {
  var tmp = {
    payload: payload
  };
  if (onStart) {
    tmp.onStart = onStart[0];
  }
  if (onUpdate) {
    tmp.onUpdate = onUpdate[0];
  }
  if (onEnd) {
    tmp.onEnd = onEnd[0];
  }
  return ReasonReact.wrapJsForReason(DragSource.default, tmp, children);
}

var DragSource$1 = /* module */[/* make */make$2];

function make$3(onStart, onUpdate, onEnd, children) {
  var tmp = { };
  if (onStart) {
    tmp.onStart = onStart[0];
  }
  if (onUpdate) {
    tmp.onUpdate = onUpdate[0];
  }
  if (onEnd) {
    tmp.onEnd = onEnd[0];
  }
  return ReasonReact.wrapJsForReason(Draggable.default, tmp, children);
}

var Draggable$1 = /* module */[/* make */make$3];

function make$4(onEnter, onOver, onLeave, onDrop, children) {
  var tmp = { };
  if (onEnter) {
    tmp.onEnter = onEnter[0];
  }
  if (onOver) {
    tmp.onOver = onOver[0];
  }
  if (onLeave) {
    tmp.onLeave = onLeave[0];
  }
  if (onDrop) {
    tmp.onDrop = onDrop[0];
  }
  return ReasonReact.wrapJsForReason(DropTarget.default, tmp, children);
}

var DropTarget$1 = /* module */[/* make */make$4];

function make$5(name, value, computed, children) {
  var tmp = {
    name: name
  };
  if (value) {
    tmp.value = value[0];
  }
  if (computed) {
    tmp.computed = computed[0];
  }
  return ReasonReact.wrapJsForReason(Getter.default, tmp, children);
}

var Getter$1 = /* module */[/* make */make$5];

function make$6(children) {
  return ReasonReact.wrapJsForReason(PluginHost.default, { }, children);
}

var PluginHost$1 = /* module */[/* make */make$6];

function convertR4fp(madeObj) {
  var returnObj = { };
  returnObj["name"] = madeObj["name"];
  returnObj["optional"] = madeObj["optional"];
  return returnObj;
}

function make$7(name, dependencies, children) {
  var tmp = { };
  if (name) {
    tmp.name = name[0];
  }
  if (dependencies) {
    tmp.dependencies = dependencies[0];
  }
  return ReasonReact.wrapJsForReason(Plugin.default, tmp, children);
}

var Plugin$1 = /* module */[
  /* convertR4fp */convertR4fp,
  /* make */make$7
];

function make$8(children) {
  return ReasonReact.wrapJsForReason(TemplateConnector.default, { }, children);
}

var TemplateConnector$1 = /* module */[/* make */make$8];

function make$9(name, params, children) {
  var tmp = { };
  if (name) {
    tmp.name = name[0];
  }
  if (params) {
    tmp.params = params[0];
  }
  return ReasonReact.wrapJsForReason(TemplatePlaceholder.default, tmp, children);
}

var TemplatePlaceholder$1 = /* module */[/* make */make$9];

function make$10(position, name, predicate, children) {
  var tmp = {
    name: name
  };
  if (position) {
    tmp.position = position[0];
  }
  if (predicate) {
    tmp.predicate = predicate[0];
  }
  return ReasonReact.wrapJsForReason(Template.default, tmp, children);
}

var Template$1 = /* module */[/* make */make$10];

exports.unwrapValue = unwrapValue;
exports.Action = Action$1;
exports.DragDropProvider = DragDropProvider$1;
exports.DragSource = DragSource$1;
exports.Draggable = Draggable$1;
exports.DropTarget = DropTarget$1;
exports.Getter = Getter$1;
exports.PluginHost = PluginHost$1;
exports.Plugin = Plugin$1;
exports.TemplateConnector = TemplateConnector$1;
exports.TemplatePlaceholder = TemplatePlaceholder$1;
exports.Template = Template$1;
/* ReasonReact Not a pure module */