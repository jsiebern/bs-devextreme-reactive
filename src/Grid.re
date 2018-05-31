external toJsUnsafe : 'a => 'b = "%identity";

let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(b)
  | `Float(f) => toJsUnsafe(f)
  | `Int(i) => toJsUnsafe(i)
  | `Date(d) => toJsUnsafe(d)
  | `Callback(c) => toJsUnsafe(c)
  | `Element(e) => toJsUnsafe(e)
  | `ObjectArray(oa) => toJsUnsafe(oa)
  | `StringArray(sa) => toJsUnsafe(sa)
  | `IntArray(ia) => toJsUnsafe(ia)
  | `FloatArray(fa) => toJsUnsafe(fa)
  | `ObjectGeneric(og) => toJsUnsafe(og)
  | `Array(ag) => toJsUnsafe(ag)
  | `Any(an) => toJsUnsafe(an)
  | `Object(_) => assert(false)
  | `Enum(_) => assert(false)
  | `EnumArray(_) => assert(false);

module ColumnChooser = {
  [@bs.deriving abstract]
  type messages = {showColumnChooser: string};

  [@bs.obj]
  external makeProps :
    (
      ~overlayComponent: 'any_r8bt=?,
      ~containerComponent: 'any_rsws=?,
      ~itemComponent: 'any_rig9=?,
      ~toggleButtonComponent: 'any_r03j=?,
      ~messages: messages=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "ColumnChooser";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_r8ep,
               "onHide": unit => unit,
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~containerComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~itemComponent:
           option(
             {
               .
               "item": {
                 .
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rodc, string) => 'any_rmwr,
                 },
                 "hidden": bool,
               },
               "disabled": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~toggleButtonComponent:
           option(
             {
               .
               "onToggle": unit => unit,
               "getMessage": string => string,
               "buttonRef": 'any_rbng => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(messages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~overlayComponent?,
          ~containerComponent?,
          ~itemComponent?,
          ~toggleButtonComponent?,
          ~messages?,
          (),
        ),
      children,
    );
};

module CustomGrouping = {
  [@bs.deriving abstract]
  type grouping = {
    [@bs.optional]
    columnName: string,
  };

  [@bs.obj]
  external makeProps :
    (
      ~getChildGroups: 'any_rp9z,
      ~grouping: array(grouping)=?,
      ~expandedGroups: 'invalidArrayType_rhi6=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomGrouping";
  let make =
      (
        ~getChildGroups:
           (array('any_r1m6), {. "columnName": string}, array('any_rs2z)) =>
           array(array('any_rm7i)),
        ~grouping: option(array(grouping))=?,
        ~expandedGroups: option('invalidArrayType_rhi6)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~getChildGroups,
          ~grouping=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              grouping,
            ),
          ~expandedGroups?,
          (),
        ),
      children,
    );
};

module CustomPaging = {
  [@bs.obj] external makeProps : (~totalCount: 'number_u=?, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomPaging";
  let make =
      (~totalCount: option([ | `Int(int) | `Float(float)])=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~totalCount=?Js.Option.map((. v) => unwrapValue(v), totalCount),
          (),
        ),
      children,
    );
};

module CustomTreeData = {
  [@bs.obj] external makeProps : (~getChildRows: 'any_ra3j, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomTreeData";
  let make =
      (
        ~getChildRows:
           ([ | `Any('any_r9t9) | `Any('any_rrn3)], array('any_rnyy)) =>
           array('any_rctj),
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~getChildRows, ()),
      children,
    );
};

module DataTypeProvider = {
  [@bs.obj]
  external makeProps :
    (
      ~for_: array(string),
      ~formatterComponent: 'any_r8yc=?,
      ~editorComponent: 'any_rnj3=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "DataTypeProvider";
  let make =
      (
        ~for_: array(string),
        ~formatterComponent:
           option(
             {
               .
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rfug, string) => 'any_r4bg,
               },
               "row": 'any_rgyg,
               "value": 'any_r8vb,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~editorComponent:
           option(
             {
               .
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rvbz, string) => 'any_rurp,
               },
               "row": 'any_rjn4,
               "value": 'any_rzhj,
               "onValueChange": 'any_rn2w => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~for_, ~formatterComponent?, ~editorComponent?, ()),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj]
  external makeProps :
    (~containerComponent: 'any_r3ul=?, ~columnComponent: 'any_rr8f=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "DragDropProvider";
  let make =
      (
        ~containerComponent:
           option(
             {
               .
               "clientOffset": {
                 .
                 "x": [ | `Int(int) | `Float(float)],
                 "y": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnComponent:
           option(
             {
               .
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rioo, string) => 'any_rb2m,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~containerComponent?, ~columnComponent?, ()),
      children,
    );
};

module EditingState = {
  [@bs.deriving abstract]
  type columnExtensions('any_rfga, 'any_r2q4, 'any_r3fb) = {
    [@bs.optional]
    columnName: string,
    editingEnabled: bool,
    createRowChange: ('any_rfga, 'any_r2q4, string) => 'any_r3fb,
  };

  [@bs.deriving abstract]
  type changes('any_rs7u, 'a) = {
    added: array('any_rs7u),
    changed: Js.t({..} as 'a),
    deleted: array([ | `Int(int) | `Float(float) | `String(string)]),
  };

  [@bs.obj]
  external makeProps :
    (
      ~createRowChange: 'any_rani=?,
      ~columnEditingEnabled: bool=?,
      ~columnExtensions: array(
                           columnExtensions('any_rfga, 'any_r2q4, 'any_r3fb),
                         )
                           =?,
      ~editingRowIds: array(
                        [ | `Int(int) | `Float(float) | `String(string)],
                      )
                        =?,
      ~defaultEditingRowIds: array(
                               [
                                 | `Int(int)
                                 | `Float(float)
                                 | `String(string)
                               ],
                             )
                               =?,
      ~onEditingRowIdsChange: 'any_red0=?,
      ~addedRows: array('any_r6kt)=?,
      ~defaultAddedRows: array('any_rvxx)=?,
      ~onAddedRowsChange: 'any_r89n=?,
      ~rowChanges: Js.t({..})=?,
      ~defaultRowChanges: Js.t({..})=?,
      ~onRowChangesChange: 'any_rqsz=?,
      ~deletedRowIds: array(
                        [ | `Int(int) | `Float(float) | `String(string)],
                      )
                        =?,
      ~defaultDeletedRowIds: array(
                               [
                                 | `Int(int)
                                 | `Float(float)
                                 | `String(string)
                               ],
                             )
                               =?,
      ~onDeletedRowIdsChange: 'any_rkx1=?,
      ~onCommitChanges: 'any_rcob,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "EditingState";
  let make =
      (
        ~createRowChange:
           option(
             (
               'any_rxl9,
               string,
               [ | `String(string) | `Int(int) | `Float(float)]
             ) =>
             'any_rtrt,
           )=?,
        ~columnEditingEnabled: option(bool)=?,
        ~columnExtensions:
           option(array(columnExtensions('any_rfga, 'any_r2q4, 'any_r3fb)))=?,
        ~editingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultEditingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onEditingRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        ~addedRows: option(array('any_r6kt))=?,
        ~defaultAddedRows: option(array('any_rvxx))=?,
        ~onAddedRowsChange: option(array('any_rppy) => unit)=?,
        ~rowChanges: option(Js.t({..}))=?,
        ~defaultRowChanges: option(Js.t({..}))=?,
        ~onRowChangesChange: option(Js.t({..}) => unit)=?,
        ~deletedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultDeletedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onDeletedRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        ~onCommitChanges: array(changes('any_rs7u, 'a)) => unit,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~createRowChange?,
          ~columnEditingEnabled?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          ~editingRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              editingRowIds,
            ),
          ~defaultEditingRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultEditingRowIds,
            ),
          ~onEditingRowIdsChange?,
          ~addedRows=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              addedRows,
            ),
          ~defaultAddedRows=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              defaultAddedRows,
            ),
          ~onAddedRowsChange?,
          ~rowChanges?,
          ~defaultRowChanges?,
          ~onRowChangesChange?,
          ~deletedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              deletedRowIds,
            ),
          ~defaultDeletedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultDeletedRowIds,
            ),
          ~onDeletedRowIdsChange?,
          ~onCommitChanges,
          (),
        ),
      children,
    );
};

module FilteringState = {
  [@bs.deriving abstract]
  type filters = {
    [@bs.optional]
    columnName: string,
    value: string,
  };

  [@bs.deriving abstract]
  type defaultFilters = {
    [@bs.optional]
    columnName: string,
    value: string,
  };

  [@bs.deriving abstract]
  type columnExtensions = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    filteringEnabled: bool,
  };

  [@bs.obj]
  external makeProps :
    (
      ~filters: array(filters)=?,
      ~defaultFilters: array(defaultFilters)=?,
      ~onFiltersChange: 'any_rw7v=?,
      ~columnExtensions: array(columnExtensions)=?,
      ~columnFilteringEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "FilteringState";
  let make =
      (
        ~filters: option(array(filters))=?,
        ~defaultFilters: option(array(defaultFilters))=?,
        ~onFiltersChange: option(array(filters) => unit)=?,
        ~columnExtensions: option(array(columnExtensions))=?,
        ~columnFilteringEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~filters=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              filters,
            ),
          ~defaultFilters=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              defaultFilters,
            ),
          ~onFiltersChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          ~columnFilteringEnabled?,
          (),
        ),
      children,
    );
};

module Grid = {
  [@bs.deriving abstract]
  type columns('any_rzvy, 'any_ruxk) = {
    [@bs.optional]
    name: string,
    title: string,
    getCellValue: ('any_rzvy, string) => 'any_ruxk,
  };

  [@bs.obj]
  external makeProps :
    (
      ~rows: array('any_rr2v)=?,
      ~getRowId: 'any_rwna=?,
      ~getCellValue: 'any_rx6w=?,
      ~columns: array(columns('any_rzvy, 'any_ruxk))=?,
      ~rootComponent: 'any_rtmx=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_rr2v))=?,
        ~getRowId:
           option(
             'any_rizg => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_r4u1, string) => 'any_rxq6)=?,
        ~columns: option(array(columns('any_rzvy, 'any_ruxk)))=?,
        ~rootComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~rows=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              rows,
            ),
          ~getRowId?,
          ~getCellValue?,
          ~columns=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columns,
            ),
          ~rootComponent?,
          (),
        ),
      children,
    );
};

module GroupPanelLayout = {
  [@bs.deriving abstract]
  type items('a) = {
    column: Js.t({..} as 'a),
    draft: bool,
  };

  [@bs.obj]
  external makeProps :
    (
      ~items: array(items('a)),
      ~onGroup: 'genericCallback=?,
      ~itemComponent: 'genericCallback,
      ~containerComponent: 'genericCallback,
      ~emptyMessageComponent: 'genericCallback,
      ~draggingEnabled: bool=?,
      ~isColumnGroupingEnabled: 'genericCallback=?,
      ~onGroupDraft: 'genericCallback=?,
      ~onGroupDraftCancel: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "GroupPanelLayout";
  let make =
      (
        ~items: array(items('a)),
        ~onGroup: option('genericCallback)=?,
        ~itemComponent: 'genericCallback,
        ~containerComponent: 'genericCallback,
        ~emptyMessageComponent: 'genericCallback,
        ~draggingEnabled: option(bool)=?,
        ~isColumnGroupingEnabled: option('genericCallback)=?,
        ~onGroupDraft: option('genericCallback)=?,
        ~onGroupDraftCancel: option('genericCallback)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~items=Js.Array.map(item => toJsUnsafe(item), items),
          ~onGroup?,
          ~itemComponent,
          ~containerComponent,
          ~emptyMessageComponent,
          ~draggingEnabled?,
          ~isColumnGroupingEnabled?,
          ~onGroupDraft?,
          ~onGroupDraftCancel?,
          (),
        ),
      children,
    );
};

module GroupingPanel = {
  [@bs.deriving jsConverter]
  type sortingDirection = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];

  [@bs.deriving jsConverter]
  type direction_enum = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];

  [@bs.deriving abstract]
  type messages = {groupByColumn: string};

  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: bool=?,
      ~showGroupingControls: bool=?,
      ~layoutComponent: 'genericCallback=?,
      ~containerComponent: 'any_rz7x=?,
      ~itemComponent: 'any_r6dz=?,
      ~emptyMessageComponent: 'any_r5ul=?,
      ~messages: messages=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "GroupingPanel";
  let make =
      (
        ~showSortingControls: option(bool)=?,
        ~showGroupingControls: option(bool)=?,
        ~layoutComponent: option('genericCallback)=?,
        ~containerComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~itemComponent:
           option(
             {
               .
               "item": {
                 .
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r29b, string) => 'any_rsjd,
                 },
                 "draft": string,
               },
               "showGroupingControls": bool,
               "showSortingControls": bool,
               "groupingEnabled": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r83p) | `Enum(direction_enum)],
                 } =>
                 unit,
               "onGroup": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~emptyMessageComponent:
           option(
             {. "getMessage": string => string} => ReasonReact.reactElement,
           )=?,
        ~messages: option(messages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~showSortingControls?,
          ~showGroupingControls?,
          ~layoutComponent?,
          ~containerComponent?,
          ~itemComponent?,
          ~emptyMessageComponent?,
          ~messages?,
          (),
        ),
      children,
    );
};

module GroupingState = {
  [@bs.deriving abstract]
  type grouping = {
    [@bs.optional]
    columnName: string,
  };

  [@bs.deriving abstract]
  type defaultGrouping = {
    [@bs.optional]
    columnName: string,
  };

  [@bs.deriving abstract]
  type columnExtensions = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    groupingEnabled: bool,
  };

  [@bs.obj]
  external makeProps :
    (
      ~grouping: array(grouping)=?,
      ~defaultGrouping: array(defaultGrouping)=?,
      ~onGroupingChange: 'any_rshe=?,
      ~expandedGroups: 'invalidArrayType_rbg5=?,
      ~defaultExpandedGroups: 'invalidArrayType_r2cx=?,
      ~onExpandedGroupsChange: 'any_rygo=?,
      ~columnExtensions: array(columnExtensions)=?,
      ~columnGroupingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "GroupingState";
  let make =
      (
        ~grouping: option(array(grouping))=?,
        ~defaultGrouping: option(array(defaultGrouping))=?,
        ~onGroupingChange: option(array(grouping) => unit)=?,
        ~expandedGroups: option('invalidArrayType_rbg5)=?,
        ~defaultExpandedGroups: option('invalidArrayType_r2cx)=?,
        ~onExpandedGroupsChange: option('invalidArrayType_rros => unit)=?,
        ~columnExtensions: option(array(columnExtensions))=?,
        ~columnGroupingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~grouping=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              grouping,
            ),
          ~defaultGrouping=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              defaultGrouping,
            ),
          ~onGroupingChange?,
          ~expandedGroups?,
          ~defaultExpandedGroups?,
          ~onExpandedGroupsChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          ~columnGroupingEnabled?,
          (),
        ),
      children,
    );
};

module IntegratedFiltering = {
  [@bs.deriving abstract]
  type columnExtensions('any_raqz, 'any_raza) = {
    [@bs.optional]
    columnName: string,
    predicate:
      (
        'any_raqz,
        {
          .
          "columnName": string,
          "value": string,
        },
        'any_raza
      ) =>
      bool,
  };

  [@bs.obj]
  external makeProps :
    (
      ~columnExtensions: array(columnExtensions('any_raqz, 'any_raza))=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedFiltering";
  let make =
      (
        ~columnExtensions:
           option(array(columnExtensions('any_raqz, 'any_raza)))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          (),
        ),
      children,
    );
};

module IntegratedGrouping = {
  [@bs.deriving abstract]
  type criteriaReturn('any_rv9y) = {
    [@bs.optional]
    key: [ | `String(string) | `Int(int) | `Float(float)],
    value: 'any_rv9y,
  };

  [@bs.deriving abstract]
  type columnExtensions('any_rr7k, 'any_rv9y) = {
    [@bs.optional]
    columnName: string,
    criteria: 'any_rr7k => criteriaReturn('any_rv9y),
  };

  [@bs.obj]
  external makeProps :
    (
      ~columnExtensions: array(columnExtensions('any_rr7k, 'any_rv9y))=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedGrouping";
  let make =
      (
        ~columnExtensions:
           option(array(columnExtensions('any_rr7k, 'any_rv9y)))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          (),
        ),
      children,
    );
};

module IntegratedPaging = {
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedPaging";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module IntegratedSelection = {
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedSelection";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module IntegratedSorting = {
  [@bs.deriving abstract]
  type columnExtensions('any_ruc5, 'any_r3vs) = {
    [@bs.optional]
    columnName: string,
    compare: ('any_ruc5, 'any_r3vs) => [ | `Int(int) | `Float(float)],
  };

  [@bs.obj]
  external makeProps :
    (
      ~columnExtensions: array(columnExtensions('any_ruc5, 'any_r3vs))=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedSorting";
  let make =
      (
        ~columnExtensions:
           option(array(columnExtensions('any_ruc5, 'any_r3vs)))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          (),
        ),
      children,
    );
};

module PagingPanel = {
  [@bs.deriving abstract]
  type messages = {
    showAll: string,
    rowsPerPage: string,
    info:
      {
        .
        "from": [ | `Int(int) | `Float(float)],
        "to": [ | `Int(int) | `Float(float)],
        "count": [ | `Int(int) | `Float(float)],
      } =>
      [ | `String(string) | `String(string)],
  };

  [@bs.obj]
  external makeProps :
    (
      ~pageSizes: 'arrayOf_r5wi=?,
      ~containerComponent: 'any_rkq6=?,
      ~messages: messages=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "PagingPanel";
  let make =
      (
        ~pageSizes:
           option([ | `IntArray(array(int)) | `FloatArray(array(float))])=?,
        ~containerComponent:
           option(
             {
               .
               "totalPages": [ | `Int(int) | `Float(float)],
               "currentPage": [ | `Int(int) | `Float(float)],
               "onCurrentPageChange": [ | `Int(int) | `Float(float)] => unit,
               "pageSize": [ | `Int(int) | `Float(float)],
               "onPageSizeChange": [ | `Int(int) | `Float(float)] => unit,
               "pageSizes": [
                 | `IntArray(array(int))
                 | `FloatArray(array(float))
               ],
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(messages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~pageSizes?, ~containerComponent?, ~messages?, ()),
      children,
    );
};

module PagingState = {
  [@bs.obj]
  external makeProps :
    (
      ~pageSize: 'number_l=?,
      ~defaultPageSize: 'number_s=?,
      ~onPageSizeChange: 'any_rutc=?,
      ~currentPage: 'number_8=?,
      ~defaultCurrentPage: 'number_p=?,
      ~onCurrentPageChange: 'any_rcke=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "PagingState";
  let make =
      (
        ~pageSize: option([ | `Int(int) | `Float(float)])=?,
        ~defaultPageSize: option([ | `Int(int) | `Float(float)])=?,
        ~onPageSizeChange: option([ | `Int(int) | `Float(float)] => unit)=?,
        ~currentPage: option([ | `Int(int) | `Float(float)])=?,
        ~defaultCurrentPage: option([ | `Int(int) | `Float(float)])=?,
        ~onCurrentPageChange: option([ | `Int(int) | `Float(float)] => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~pageSize=?Js.Option.map((. v) => unwrapValue(v), pageSize),
          ~defaultPageSize=?
            Js.Option.map((. v) => unwrapValue(v), defaultPageSize),
          ~onPageSizeChange?,
          ~currentPage=?Js.Option.map((. v) => unwrapValue(v), currentPage),
          ~defaultCurrentPage=?
            Js.Option.map((. v) => unwrapValue(v), defaultCurrentPage),
          ~onCurrentPageChange?,
          (),
        ),
      children,
    );
};

module RowDetailState = {
  [@bs.obj]
  external makeProps :
    (
      ~expandedRowIds: array(
                         [ | `Int(int) | `Float(float) | `String(string)],
                       )
                         =?,
      ~defaultExpandedRowIds: array(
                                [
                                  | `Int(int)
                                  | `Float(float)
                                  | `String(string)
                                ],
                              )
                                =?,
      ~onExpandedRowIdsChange: 'any_rhkd=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "RowDetailState";
  let make =
      (
        ~expandedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultExpandedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onExpandedRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~expandedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              expandedRowIds,
            ),
          ~defaultExpandedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultExpandedRowIds,
            ),
          ~onExpandedRowIdsChange?,
          (),
        ),
      children,
    );
};

module SearchPanel = {
  [@bs.deriving abstract]
  type messages = {searchPlaceholder: string};

  [@bs.obj]
  external makeProps :
    (~inputComponent: 'any_rezf=?, ~messages: messages=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SearchPanel";
  let make =
      (
        ~inputComponent:
           option(
             {
               .
               "value": string,
               "onValueChange": unit => unit,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(messages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~inputComponent?, ~messages?, ()),
      children,
    );
};

module SearchState = {
  [@bs.obj]
  external makeProps :
    (
      ~value: string=?,
      ~defaultValue: string=?,
      ~onValueChange: 'any_rzwo=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SearchState";
  let make =
      (
        ~value: option(string)=?,
        ~defaultValue: option(string)=?,
        ~onValueChange: option(string => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~value?, ~defaultValue?, ~onValueChange?, ()),
      children,
    );
};

module SelectionState = {
  [@bs.obj]
  external makeProps :
    (
      ~selection: array([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~defaultSelection: array(
                           [ | `Int(int) | `Float(float) | `String(string)],
                         )
                           =?,
      ~onSelectionChange: 'any_r0u6=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SelectionState";
  let make =
      (
        ~selection:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultSelection:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onSelectionChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~selection=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              selection,
            ),
          ~defaultSelection=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultSelection,
            ),
          ~onSelectionChange?,
          (),
        ),
      children,
    );
};

module SortingState = {
  [@bs.deriving jsConverter]
  type direction = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];

  [@bs.deriving abstract]
  type sorting = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    direction,
  };

  [@bs.deriving abstract]
  type defaultSorting = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    direction,
  };

  [@bs.deriving abstract]
  type columnExtensions = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    sortingEnabled: bool,
  };

  [@bs.obj]
  external makeProps :
    (
      ~sorting: array(sorting)=?,
      ~defaultSorting: array(defaultSorting)=?,
      ~onSortingChange: 'any_reyj=?,
      ~columnExtensions: array(columnExtensions)=?,
      ~columnSortingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SortingState";
  let make =
      (
        ~sorting: option(array(sorting))=?,
        ~defaultSorting: option(array(defaultSorting))=?,
        ~onSortingChange: option(array(sorting) => unit)=?,
        ~columnExtensions: option(array(columnExtensions))=?,
        ~columnSortingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~sorting=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              sorting,
            ),
          ~defaultSorting=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              defaultSorting,
            ),
          ~onSortingChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          ~columnSortingEnabled?,
          (),
        ),
      children,
    );
};

module StaticTableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~headerRows: array('any_rern)=?,
      ~bodyRows: array('any_rkl4),
      ~columns: array('any_rqh3),
      ~minWidth: 'number_n,
      ~containerComponent: 'genericCallback,
      ~tableComponent: 'genericCallback,
      ~headComponent: 'genericCallback=?,
      ~bodyComponent: 'genericCallback,
      ~rowComponent: 'genericCallback,
      ~cellComponent: 'genericCallback,
      ~getCellColSpan: 'genericCallback,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "StaticTableLayout";
  let make =
      (
        ~headerRows: option(array('any_rern))=?,
        ~bodyRows: array('any_rkl4),
        ~columns: array('any_rqh3),
        ~minWidth: [ | `Int(int) | `Float(float)],
        ~containerComponent: 'genericCallback,
        ~tableComponent: 'genericCallback,
        ~headComponent: option('genericCallback)=?,
        ~bodyComponent: 'genericCallback,
        ~rowComponent: 'genericCallback,
        ~cellComponent: 'genericCallback,
        ~getCellColSpan: 'genericCallback,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~headerRows?,
          ~bodyRows,
          ~columns,
          ~minWidth=unwrapValue(minWidth),
          ~containerComponent,
          ~tableComponent,
          ~headComponent?,
          ~bodyComponent,
          ~rowComponent,
          ~cellComponent,
          ~getCellColSpan,
          (),
        ),
      children,
    );
};

module TableBandHeader = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~columnBands: array('any_rb4w)=?,
      ~cellComponent: 'any_rm1w=?,
      ~rowComponent: 'any_rjp8=?,
      ~bandedHeaderCellComponent: 'genericCallback=?,
      ~invisibleCellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableBandHeader";
  let make =
      (
        ~columnBands: option(array('any_rb4w))=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r6m7,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r9jq, string) => 'any_rdrk,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        ~bandedHeaderCellComponent: option('genericCallback)=?,
        ~invisibleCellComponent: option('genericCallback)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columnBands=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnBands,
            ),
          ~cellComponent?,
          ~rowComponent?,
          ~bandedHeaderCellComponent?,
          ~invisibleCellComponent?,
          (),
        ),
      children,
    );
};

module TableColumnReordering = {
  [@bs.obj]
  external makeProps :
    (
      ~order: array(string)=?,
      ~defaultOrder: array(string)=?,
      ~onOrderChange: 'any_rylq=?,
      ~tableContainerComponent: 'genericCallback=?,
      ~rowComponent: 'genericCallback=?,
      ~cellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableColumnReordering";
  let make =
      (
        ~order: option(array(string))=?,
        ~defaultOrder: option(array(string))=?,
        ~onOrderChange: option(array(string) => unit)=?,
        ~tableContainerComponent: option('genericCallback)=?,
        ~rowComponent: option('genericCallback)=?,
        ~cellComponent: option('genericCallback)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~order?,
          ~defaultOrder?,
          ~onOrderChange?,
          ~tableContainerComponent?,
          ~rowComponent?,
          ~cellComponent?,
          (),
        ),
      children,
    );
};

module TableColumnResizing = {
  [@bs.deriving abstract]
  type defaultColumnWidths = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    width: [ | `Int(int) | `Float(float)],
  };

  [@bs.deriving abstract]
  type columnWidths = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    width: [ | `Int(int) | `Float(float)],
  };

  [@bs.deriving abstract]
  type nextColumnWidths = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    width: [ | `Int(int) | `Float(float)],
  };

  [@bs.obj]
  external makeProps :
    (
      ~defaultColumnWidths: array(defaultColumnWidths)=?,
      ~columnWidths: array(columnWidths)=?,
      ~onColumnWidthsChange: 'any_rm13=?,
      ~minColumnWidth: 'number_b=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableColumnResizing";
  let make =
      (
        ~defaultColumnWidths: option(array(defaultColumnWidths))=?,
        ~columnWidths: option(array(columnWidths))=?,
        ~onColumnWidthsChange: option(array(nextColumnWidths) => unit)=?,
        ~minColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~defaultColumnWidths=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              defaultColumnWidths,
            ),
          ~columnWidths=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnWidths,
            ),
          ~onColumnWidthsChange?,
          ~minColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), minColumnWidth),
          (),
        ),
      children,
    );
};

module TableColumnVisibility = {
  [@bs.deriving abstract]
  type messages = {noColumns: string};

  [@bs.deriving abstract]
  type columnExtensions = {
    [@bs.optional]
    columnName: string,
    [@bs.optional]
    togglingEnabled: bool,
  };

  [@bs.obj]
  external makeProps :
    (
      ~hiddenColumnNames: array(string)=?,
      ~defaultHiddenColumnNames: array(string)=?,
      ~emptyMessageComponent: 'any_rf1b=?,
      ~onHiddenColumnNamesChange: 'any_r8ze=?,
      ~messages: messages=?,
      ~columnExtensions: array(columnExtensions)=?,
      ~columnTogglingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableColumnVisibility";
  let make =
      (
        ~hiddenColumnNames: option(array(string))=?,
        ~defaultHiddenColumnNames: option(array(string))=?,
        ~emptyMessageComponent:
           option(
             {. "getMessage": string => string} => ReasonReact.reactElement,
           )=?,
        ~onHiddenColumnNamesChange: option(array(string) => unit)=?,
        ~messages: option(messages)=?,
        ~columnExtensions: option(array(columnExtensions))=?,
        ~columnTogglingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~hiddenColumnNames?,
          ~defaultHiddenColumnNames?,
          ~emptyMessageComponent?,
          ~onHiddenColumnNamesChange?,
          ~messages?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          ~columnTogglingEnabled?,
          (),
        ),
      children,
    );
};

module TableEditColumn = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];

  [@bs.deriving jsConverter]
  type id = [
    | [@bs.as "add"] `Add
    | [@bs.as "edit"] `Edit
    | [@bs.as "delete"] `Delete
    | [@bs.as "commit"] `Commit
    | [@bs.as "cancel"] `Cancel
  ];

  [@bs.deriving abstract]
  type messages = {
    addCommand: string,
    editCommand: string,
    deleteCommand: string,
    commitCommand: string,
    cancelCommand: string,
  };

  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rf95=?,
      ~headerCellComponent: 'any_rgpl=?,
      ~commandComponent: 'any_rqg4=?,
      ~showAddCommand: bool=?,
      ~showEditCommand: bool=?,
      ~showDeleteCommand: bool=?,
      ~width: 'union_rj48=?,
      ~messages: messages=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableEditColumn";
  let make =
      (
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rh50,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rsoz, string) => 'any_rzkc,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r3ro,
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~headerCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rqvp,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rucp, string) => 'any_r0iw,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~commandComponent:
           option(
             {
               .
               "id": id,
               "text": string,
               "onExecute": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~showAddCommand: option(bool)=?,
        ~showEditCommand: option(bool)=?,
        ~showDeleteCommand: option(bool)=?,
        ~width: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~messages: option(messages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~cellComponent?,
          ~headerCellComponent?,
          ~commandComponent?,
          ~showAddCommand?,
          ~showEditCommand?,
          ~showDeleteCommand?,
          ~width=?Js.Option.map((. v) => unwrapValue(v), width),
          ~messages?,
          (),
        ),
      children,
    );
};

module TableEditRow = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_y=?,
      ~cellComponent: 'any_r1hx=?,
      ~rowComponent: 'any_r0bt=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableEditRow";
  let make =
      (
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r9j6,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rjn0, string) => 'any_ryk6,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rktu,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rfun, string) => 'any_ryef,
               },
               "value": 'any_rdg0,
               "editingEnabled": bool,
               "onValueChange": 'any_rh3s => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rj7p,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_roai,
             } =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~rowHeight=?Js.Option.map((. v) => unwrapValue(v), rowHeight),
          ~cellComponent?,
          ~rowComponent?,
          (),
        ),
      children,
    );
};

module TableFilterRow = {
  [@bs.deriving abstract]
  type messages = {filterPlaceholder: string};

  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_5=?,
      ~messages: messages=?,
      ~cellComponent: 'any_rux5=?,
      ~rowComponent: 'any_rfoc=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableFilterRow";
  let make =
      (
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~messages: option(messages)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rh3d,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rq2i, string) => 'any_ru88,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "filter": {
                 .
                 "columnName": string,
                 "value": string,
               },
               "onFilter":
                 {
                   .
                   "columnName": string,
                   "value": string,
                 } =>
                 unit,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r5ii, string) => 'any_rsvr,
               },
               "filteringEnabled": bool,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~rowHeight=?Js.Option.map((. v) => unwrapValue(v), rowHeight),
          ~messages?,
          ~cellComponent?,
          ~rowComponent?,
          (),
        ),
      children,
    );
};

module TableGroupRow = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];

  [@bs.deriving abstract]
  type columnExtensions = {
    [@bs.optional]
    columnName: string,
    showWhenGrouped: bool,
  };

  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rv2e=?,
      ~rowComponent: 'any_rk75=?,
      ~indentCellComponent: 'any_r7b8=?,
      ~indentColumnWidth: 'number_b=?,
      ~showColumnsWhenGrouped: bool=?,
      ~columnExtensions: array(columnExtensions)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableGroupRow";
  let make =
      (
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rl3y,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r9rh, string) => 'any_ruik,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rq1m,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rm1m, string) => 'any_rn2a,
               },
               "expanded": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_riit,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_r6b7,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r6tx,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rtg2, string) => 'any_raqx,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rgcf,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rwd8, string) => 'any_r2bc,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~showColumnsWhenGrouped: option(bool)=?,
        ~columnExtensions: option(array(columnExtensions))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~cellComponent?,
          ~rowComponent?,
          ~indentCellComponent?,
          ~indentColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), indentColumnWidth),
          ~showColumnsWhenGrouped?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          (),
        ),
      children,
    );
};

module TableHeaderRow = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];

  [@bs.deriving jsConverter]
  type sortingDirection = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];

  [@bs.deriving jsConverter]
  type direction_enum = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];

  [@bs.deriving abstract]
  type messages = {sortingHint: string};

  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: bool=?,
      ~showGroupingControls: bool=?,
      ~cellComponent: 'any_r748=?,
      ~rowComponent: 'any_rwhl=?,
      ~messages: messages=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableHeaderRow";
  let make =
      (
        ~showSortingControls: option(bool)=?,
        ~showGroupingControls: option(bool)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r2yl,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r3z2, string) => 'any_r16r,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rlut, string) => 'any_rkyx,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r95d) | `Enum(direction_enum)],
                   "keepOther": bool,
                 } =>
                 unit,
               "showGroupingControls": bool,
               "groupingEnabled": bool,
               "onGroup": unit => unit,
               "resizingEnabled": bool,
               "onWidthChange":
                 {. "shift": [ | `Int(int) | `Float(float)]} => unit,
               "onWidthDraft":
                 {. "shift": [ | `Int(int) | `Float(float)]} => unit,
               "onWidthDraftCancel": unit => unit,
               "draggingEnabled": bool,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        ~messages: option(messages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~showSortingControls?,
          ~showGroupingControls?,
          ~cellComponent?,
          ~rowComponent?,
          ~messages?,
          (),
        ),
      children,
    );
};

module TableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~columns: array('any_rrgl),
      ~minColumnWidth: 'number_w,
      ~layoutComponent: 'genericCallback,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableLayout";
  let make =
      (
        ~columns: array('any_rrgl),
        ~minColumnWidth: [ | `Int(int) | `Float(float)],
        ~layoutComponent: 'genericCallback,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columns,
          ~minColumnWidth=unwrapValue(minColumnWidth),
          ~layoutComponent,
          (),
        ),
      children,
    );
};

module TableRowDetail = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~contentComponent: 'any_rp0k=?,
      ~toggleCellComponent: 'any_rbf2=?,
      ~cellComponent: 'any_rx1d=?,
      ~rowComponent: 'any_r3yd=?,
      ~toggleColumnWidth: 'number_r=?,
      ~rowHeight: 'number_m=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_rdyi} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rvvk,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rizi, string) => 'any_r3tn,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rx2n,
               "expanded": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_re3a,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r2xs, string) => 'any_rpa4,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r3k8,
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rxx8,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rif3,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~toggleColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~contentComponent?,
          ~toggleCellComponent?,
          ~cellComponent?,
          ~rowComponent?,
          ~toggleColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), toggleColumnWidth),
          ~rowHeight=?Js.Option.map((. v) => unwrapValue(v), rowHeight),
          (),
        ),
      children,
    );
};

module TableSelection = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~headerCellComponent: 'any_ruvu=?,
      ~cellComponent: 'any_rhpn=?,
      ~rowComponent: 'genericCallback=?,
      ~highlightRow: bool=?,
      ~selectByRowClick: bool=?,
      ~showSelectAll: bool=?,
      ~showSelectionColumn: bool=?,
      ~selectionColumnWidth: 'number_9=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableSelection";
  let make =
      (
        ~headerCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rfmj,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r2hd, string) => 'any_rkfi,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "disabled": bool,
               "allSelected": bool,
               "someSelected": bool,
               "onToggle": bool => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rc53,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rwr9, string) => 'any_r4hm,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rowx,
               "selected": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option('genericCallback)=?,
        ~highlightRow: option(bool)=?,
        ~selectByRowClick: option(bool)=?,
        ~showSelectAll: option(bool)=?,
        ~showSelectionColumn: option(bool)=?,
        ~selectionColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~headerCellComponent?,
          ~cellComponent?,
          ~rowComponent?,
          ~highlightRow?,
          ~selectByRowClick?,
          ~showSelectAll?,
          ~showSelectionColumn?,
          ~selectionColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), selectionColumnWidth),
          (),
        ),
      children,
    );
};

module TableTreeColumn = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~for_: string=?,
      ~showSelectionControls: bool=?,
      ~showSelectAll: bool=?,
      ~cellComponent: 'any_re47=?,
      ~indentComponent: 'any_rw2x=?,
      ~expandButtonComponent: 'any_r7mf=?,
      ~checkboxComponent: 'any_rfch=?,
      ~contentComponent: 'any_rykk=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableTreeColumn";
  let make =
      (
        ~for_: option(string)=?,
        ~showSelectionControls: option(bool)=?,
        ~showSelectAll: option(bool)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rz1f,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r857, string) => 'any_rues,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rdq3,
               "row": 'any_rjez,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rj6k, string) => 'any_rhdx,
               },
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentComponent:
           option(
             {. "level": [ | `Int(int) | `Float(float)]} =>
             ReasonReact.reactElement,
           )=?,
        ~expandButtonComponent:
           option(
             {
               .
               "visible": bool,
               "expanded": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~checkboxComponent:
           option(
             {
               .
               "disabled": bool,
               "checked": bool,
               "indeterminate": bool,
               "onChange": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~contentComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~for_?,
          ~showSelectionControls?,
          ~showSelectAll?,
          ~cellComponent?,
          ~indentComponent?,
          ~expandButtonComponent?,
          ~checkboxComponent?,
          ~contentComponent?,
          (),
        ),
      children,
    );
};

module Table = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];

  [@bs.deriving abstract]
  type columnExtensions = {
    [@bs.optional]
    columnName: string,
    width: [ | `Int(int) | `Float(float)],
    align,
    wordWrapEnabled: bool,
  };

  [@bs.deriving abstract]
  type messages = {noData: string};

  [@bs.obj]
  external makeProps :
    (
      ~layoutComponent: 'genericCallback=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_rqf8=?,
      ~rowComponent: 'any_rtmd=?,
      ~noDataCellComponent: 'any_rleg=?,
      ~noDataRowComponent: 'any_rfb0=?,
      ~stubRowComponent: 'any_r2mv=?,
      ~stubCellComponent: 'any_rllz=?,
      ~stubHeaderCellComponent: 'any_rxox=?,
      ~columnExtensions: array(columnExtensions)=?,
      ~messages: messages=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "Table";
  let make =
      (
        ~layoutComponent: option('genericCallback)=?,
        ~tableComponent: option(ReasonReact.reactElement)=?,
        ~headComponent: option(ReasonReact.reactElement)=?,
        ~bodyComponent: option(ReasonReact.reactElement)=?,
        ~containerComponent: option(ReasonReact.reactElement)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rxcy,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rcvn, string) => 'any_row8,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_r9o7,
               "row": 'any_rpzh,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r081, string) => 'any_rji5,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rlrg,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rk2c,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~noDataCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rqwa,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r3l1, string) => 'any_rcku,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~noDataRowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_ra5v,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~stubRowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rga7,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~stubCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rg4r,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rbyc, string) => 'any_rgf6,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~stubHeaderCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r6m2,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r78b, string) => 'any_ry3w,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnExtensions: option(array(columnExtensions))=?,
        ~messages: option(messages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~layoutComponent?,
          ~tableComponent?,
          ~headComponent?,
          ~bodyComponent?,
          ~containerComponent?,
          ~cellComponent?,
          ~rowComponent?,
          ~noDataCellComponent?,
          ~noDataRowComponent?,
          ~stubRowComponent?,
          ~stubCellComponent?,
          ~stubHeaderCellComponent?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnExtensions,
            ),
          ~messages?,
          (),
        ),
      children,
    );
};

module Toolbar = {
  [@bs.obj]
  external makeProps :
    (
      ~rootComponent: 'any_rg5e=?,
      ~flexibleSpaceComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "Toolbar";
  let make =
      (
        ~rootComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~flexibleSpaceComponent: option('genericCallback)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~rootComponent?, ~flexibleSpaceComponent?, ()),
      children,
    );
};

module TreeDataState = {
  [@bs.obj]
  external makeProps :
    (
      ~expandedRowIds: array(
                         [ | `Int(int) | `Float(float) | `String(string)],
                       )
                         =?,
      ~defaultExpandedRowIds: array(
                                [
                                  | `Int(int)
                                  | `Float(float)
                                  | `String(string)
                                ],
                              )
                                =?,
      ~onExpandedRowIdsChange: 'any_ry1w=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TreeDataState";
  let make =
      (
        ~expandedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultExpandedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onExpandedRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~expandedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              expandedRowIds,
            ),
          ~defaultExpandedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultExpandedRowIds,
            ),
          ~onExpandedRowIdsChange?,
          (),
        ),
      children,
    );
};

module VirtualTableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~minWidth: 'number_w,
      ~minColumnWidth: 'number_7,
      ~height: 'number_o,
      ~headerRows: array('any_r1hq)=?,
      ~bodyRows: array('any_rkwe),
      ~columns: array('any_rg4v),
      ~cellComponent: 'genericCallback,
      ~rowComponent: 'genericCallback,
      ~bodyComponent: 'genericCallback,
      ~headComponent: 'genericCallback=?,
      ~tableComponent: 'genericCallback,
      ~headTableComponent: 'genericCallback=?,
      ~containerComponent: 'genericCallback,
      ~estimatedRowHeight: 'number_i,
      ~getCellColSpan: 'genericCallback,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "VirtualTableLayout";
  let make =
      (
        ~minWidth: [ | `Int(int) | `Float(float)],
        ~minColumnWidth: [ | `Int(int) | `Float(float)],
        ~height: [ | `Int(int) | `Float(float)],
        ~headerRows: option(array('any_r1hq))=?,
        ~bodyRows: array('any_rkwe),
        ~columns: array('any_rg4v),
        ~cellComponent: 'genericCallback,
        ~rowComponent: 'genericCallback,
        ~bodyComponent: 'genericCallback,
        ~headComponent: option('genericCallback)=?,
        ~tableComponent: 'genericCallback,
        ~headTableComponent: option('genericCallback)=?,
        ~containerComponent: 'genericCallback,
        ~estimatedRowHeight: [ | `Int(int) | `Float(float)],
        ~getCellColSpan: 'genericCallback,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~minWidth=unwrapValue(minWidth),
          ~minColumnWidth=unwrapValue(minColumnWidth),
          ~height=unwrapValue(height),
          ~headerRows?,
          ~bodyRows,
          ~columns,
          ~cellComponent,
          ~rowComponent,
          ~bodyComponent,
          ~headComponent?,
          ~tableComponent,
          ~headTableComponent?,
          ~containerComponent,
          ~estimatedRowHeight=unwrapValue(estimatedRowHeight),
          ~getCellColSpan,
          (),
        ),
      children,
    );
};
