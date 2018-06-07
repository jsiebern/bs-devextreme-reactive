// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Js_option = require("bs-platform/lib/js/js_option.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");
var DxReactCore = require("@devexpress/dx-react-core");

function unwrapValue(param) {
  var variant = param[0];
  if (variant !== -908856609) {
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
  return ReasonReact.wrapJsForReason(DxReactCore.Action, {
              name: name,
              action: action
            }, children);
}

var Action = /* module */[/* make */make];

function make$1(onChange, children) {
  var tmp = { };
  if (onChange) {
    tmp.onChange = onChange[0];
  }
  return ReasonReact.wrapJsForReason(DxReactCore.DragDropProvider, tmp, children);
}

var DragDropProvider = /* module */[/* make */make$1];

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
  return ReasonReact.wrapJsForReason(DxReactCore.DragSource, tmp, children);
}

var DragSource = /* module */[/* make */make$2];

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
  return ReasonReact.wrapJsForReason(DxReactCore.Draggable, tmp, children);
}

var Draggable = /* module */[/* make */make$3];

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
  return ReasonReact.wrapJsForReason(DxReactCore.DropTarget, tmp, children);
}

var DropTarget = /* module */[/* make */make$4];

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
  return ReasonReact.wrapJsForReason(DxReactCore.Getter, tmp, children);
}

var Getter = /* module */[/* make */make$5];

function make$6(children) {
  return ReasonReact.wrapJsForReason(DxReactCore.PluginHost, { }, children);
}

var PluginHost = /* module */[/* make */make$6];

function make$7(prim, prim$1, _) {
  var tmp = { };
  if (prim) {
    tmp.name = prim[0];
  }
  if (prim$1) {
    tmp.optional = prim$1[0];
  }
  return tmp;
}

function unwrap(obj) {
  var unwrappedMap = { };
  var match = obj.name;
  if (match !== undefined) {
    unwrappedMap["name"] = match;
  }
  var match$1 = obj.optional;
  if (match$1 !== undefined) {
    unwrappedMap["optional"] = match$1;
  }
  return unwrappedMap;
}

var Dependencies = /* module */[
  /* make */make$7,
  /* unwrap */unwrap
];

function make$8(name, dependencies, children) {
  var tmp = { };
  if (name) {
    tmp.name = name[0];
  }
  var tmp$1 = Js_option.map((function (v) {
          return v.map(unwrap);
        }), dependencies);
  if (tmp$1) {
    tmp.dependencies = tmp$1[0];
  }
  return ReasonReact.wrapJsForReason(DxReactCore.Plugin, tmp, children);
}

var Plugin = /* module */[
  /* Dependencies */Dependencies,
  /* make */make$8
];

function make$9(children) {
  return ReasonReact.wrapJsForReason(DxReactCore.RefHolder, { }, children);
}

var RefHolder = /* module */[/* make */make$9];

function make$10(children) {
  return ReasonReact.wrapJsForReason(DxReactCore.Sizer, { }, children);
}

var Sizer = /* module */[/* make */make$10];

function make$11(children) {
  return ReasonReact.wrapJsForReason(DxReactCore.TemplateConnector, { }, children);
}

var TemplateConnector = /* module */[/* make */make$11];

function make$12(name, params, children) {
  var tmp = { };
  if (name) {
    tmp.name = name[0];
  }
  if (params) {
    tmp.params = params[0];
  }
  return ReasonReact.wrapJsForReason(DxReactCore.TemplatePlaceholder, tmp, children);
}

var TemplatePlaceholder = /* module */[/* make */make$12];

function make$13(position, name, predicate, children) {
  var tmp = {
    name: name
  };
  if (position) {
    tmp.position = position[0];
  }
  if (predicate) {
    tmp.predicate = predicate[0];
  }
  return ReasonReact.wrapJsForReason(DxReactCore.Template, tmp, children);
}

var Template = /* module */[/* make */make$13];

exports.unwrapValue = unwrapValue;
exports.Action = Action;
exports.DragDropProvider = DragDropProvider;
exports.DragSource = DragSource;
exports.Draggable = Draggable;
exports.DropTarget = DropTarget;
exports.Getter = Getter;
exports.PluginHost = PluginHost;
exports.Plugin = Plugin;
exports.RefHolder = RefHolder;
exports.Sizer = Sizer;
exports.TemplateConnector = TemplateConnector;
exports.TemplatePlaceholder = TemplatePlaceholder;
exports.Template = Template;
/* ReasonReact Not a pure module */
