external toJsUnsafe : 'a => 'b = "%identity";

let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(Js.Boolean.to_js_boolean(b))
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
  | `Object(_) => assert false
  | `Enum(_) => assert false
  | `EnumArray(_) => assert false;

module ColumnChooser = {
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~showColumnChooser: string=?, unit) => typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "showColumnChooser",
        toJsUnsafe(getFromMessages(madeObj, "showColumnChooser")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~overlayComponent: 'any_rigw=?,
      ~containerComponent: 'any_rw95=?,
      ~itemComponent: 'any_rfzh=?,
      ~toggleButtonComponent: 'any_rbee=?,
      ~messages: 'any_rj07=?,
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
               "target": 'any_rgo2,
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
                   "getCellValue": ('any_rusc, string) => 'any_rgxc,
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
               "buttonRef": 'any_rj9c => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(typeMessages)=?,
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
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module CustomGrouping = {
  type typeGrouping;
  [@bs.obj]
  external makeGrouping : (~columnName: string, unit) => typeGrouping = "";
  [@bs.get_index] external getFromGrouping : (typeGrouping, string) => 'a = "";
  let convertGrouping = (madeObj: typeGrouping) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromGrouping(madeObj, "columnName")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~getChildGroups: 'any_rl6j,
      ~grouping: array(typeGrouping)=?,
      ~expandedGroups: 'invalidArrayType_r8tu=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomGrouping";
  let make =
      (
        ~getChildGroups:
           (array('any_rclc), {. "columnName": string}, array('any_rdj4)) =>
           array(array('any_r5gy)),
        ~grouping: option(array(typeGrouping))=?,
        ~expandedGroups: option('invalidArrayType_r8tu)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~getChildGroups,
          ~grouping=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertGrouping(item)), v),
              grouping,
            ),
          ~expandedGroups?,
          (),
        ),
      children,
    );
};

module CustomPaging = {
  [@bs.obj] external makeProps : (~totalCount: 'number_f=?, unit) => _ = "";
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

module DataTypeProvider = {
  [@bs.obj]
  external makeProps :
    (
      ~_for: array(string),
      ~formatterComponent: 'any_rh0n=?,
      ~editorComponent: 'any_rpd4=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "DataTypeProvider";
  let make =
      (
        ~_for: array(string),
        ~formatterComponent:
           option(
             {
               .
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r0e3, string) => 'any_rxoc,
               },
               "row": 'any_roh7,
               "value": 'any_rajt,
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
                 "getCellValue": ('any_r7bn, string) => 'any_rebe,
               },
               "row": 'any_r4ve,
               "value": 'any_r2wg,
               "onValueChange": 'any_rvpo => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~_for, ~formatterComponent?, ~editorComponent?, ()),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj]
  external makeProps :
    (~containerComponent: 'any_rnx0=?, ~columnComponent: 'any_rvje=?, unit) =>
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
                 "getCellValue": ('any_ruc4, string) => 'any_r6hy,
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
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (
      ~columnName: string,
      ~editingEnabled: Js.boolean=?,
      ~createRowChange: 'any_re1k=?,
      unit
    ) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "editingEnabled",
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Boolean.to_js_boolean(v),
          getFromColumnExtensions(madeObj, "editingEnabled"),
        ),
      ),
    );
    Js.Dict.set(
      returnObj,
      "createRowChange",
      toJsUnsafe(getFromColumnExtensions(madeObj, "createRowChange")),
    );
    returnObj;
  };
  type typeChanges;
  [@bs.obj]
  external makeChanges :
    (
      ~added: array('any_rfo3)=?,
      ~changed: Js.t({..})=?,
      ~deleted: array([ | `Int(int) | `Float(float) | `String(string)])=?,
      unit
    ) =>
    typeChanges =
    "";
  [@bs.get_index] external getFromChanges : (typeChanges, string) => 'a = "";
  let convertChanges = (madeObj: typeChanges) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "added",
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Array.map(item => toJsUnsafe(item), v),
          getFromChanges(madeObj, "added"),
        ),
      ),
    );
    Js.Dict.set(
      returnObj,
      "changed",
      toJsUnsafe(getFromChanges(madeObj, "changed")),
    );
    Js.Dict.set(
      returnObj,
      "deleted",
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
          getFromChanges(madeObj, "deleted"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~createRowChange: 'any_re5h=?,
      ~columnEditingEnabled: Js.boolean=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
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
      ~onEditingRowIdsChange: 'any_r102=?,
      ~addedRows: array('any_r0p7)=?,
      ~defaultAddedRows: array('any_rtze)=?,
      ~onAddedRowsChange: 'any_rw6f=?,
      ~rowChanges: Js.t({..})=?,
      ~defaultRowChanges: Js.t({..})=?,
      ~onRowChangesChange: 'any_rr5o=?,
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
      ~onDeletedRowIdsChange: 'any_ranw=?,
      ~onCommitChanges: 'any_rbg6,
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
               'any_rz45,
               string,
               [ | `String(string) | `Int(int) | `Float(float)]
             ) =>
             'any_rxm3,
           )=?,
        ~columnEditingEnabled: option(bool)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~editingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultEditingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onEditingRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        ~addedRows: option(array('any_r0p7))=?,
        ~defaultAddedRows: option(array('any_rtze))=?,
        ~onAddedRowsChange: option(array('any_rlhk) => unit)=?,
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
        ~onCommitChanges: array(typeChanges) => unit,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~createRowChange?,
          ~columnEditingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnEditingEnabled,
            ),
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
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
  type typeFilters;
  [@bs.obj]
  external makeFilters :
    (~columnName: string, ~value: string=?, unit) => typeFilters =
    "";
  [@bs.get_index] external getFromFilters : (typeFilters, string) => 'a = "";
  let convertFilters = (madeObj: typeFilters) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromFilters(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "value",
      toJsUnsafe(getFromFilters(madeObj, "value")),
    );
    returnObj;
  };
  type typeDefaultFilters;
  [@bs.obj]
  external makeDefaultFilters :
    (~columnName: string, ~value: string=?, unit) => typeDefaultFilters =
    "";
  [@bs.get_index]
  external getFromDefaultFilters : (typeDefaultFilters, string) => 'a = "";
  let convertDefaultFilters = (madeObj: typeDefaultFilters) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromDefaultFilters(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "value",
      toJsUnsafe(getFromDefaultFilters(madeObj, "value")),
    );
    returnObj;
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~filteringEnabled: Js.boolean, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "filteringEnabled",
      toJsUnsafe(
        Js.Boolean.to_js_boolean(
          getFromColumnExtensions(madeObj, "filteringEnabled"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~filters: array(typeFilters)=?,
      ~defaultFilters: array(typeDefaultFilters)=?,
      ~onFiltersChange: 'any_rzq3=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnFilteringEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "FilteringState";
  let make =
      (
        ~filters: option(array(typeFilters))=?,
        ~defaultFilters: option(array(typeDefaultFilters))=?,
        ~onFiltersChange: option(array(typeFilters) => unit)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~columnFilteringEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~filters=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertFilters(item)), v),
              filters,
            ),
          ~defaultFilters=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDefaultFilters(item)),
                  v,
                ),
              defaultFilters,
            ),
          ~onFiltersChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnFilteringEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnFilteringEnabled,
            ),
          (),
        ),
      children,
    );
};

module Grid = {
  type typeColumns;
  [@bs.obj]
  external makeColumns :
    (~name: string, ~title: string=?, ~getCellValue: 'any_rfaw=?, unit) =>
    typeColumns =
    "";
  [@bs.get_index] external getFromColumns : (typeColumns, string) => 'a = "";
  let convertColumns = (madeObj: typeColumns) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "name",
      toJsUnsafe(getFromColumns(madeObj, "name")),
    );
    Js.Dict.set(
      returnObj,
      "title",
      toJsUnsafe(getFromColumns(madeObj, "title")),
    );
    Js.Dict.set(
      returnObj,
      "getCellValue",
      toJsUnsafe(getFromColumns(madeObj, "getCellValue")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~rows: array('any_r9nn)=?,
      ~getRowId: 'any_r6nh=?,
      ~getCellValue: 'any_rml9=?,
      ~columns: array(typeColumns)=?,
      ~rootComponent: 'any_rqso=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_r9nn))=?,
        ~getRowId:
           option(
             'any_ruta => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_r0za, string) => 'any_r8ok)=?,
        ~columns: option(array(typeColumns))=?,
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
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertColumns(item)), v),
              columns,
            ),
          ~rootComponent?,
          (),
        ),
      children,
    );
};

module GroupPanelLayout = {
  type typeItems;
  [@bs.obj]
  external makeItems :
    (~column: Js.t({..})=?, ~draft: Js.boolean=?, unit) => typeItems =
    "";
  [@bs.get_index] external getFromItems : (typeItems, string) => 'a = "";
  let convertItems = (madeObj: typeItems) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "column",
      toJsUnsafe(getFromItems(madeObj, "column")),
    );
    Js.Dict.set(
      returnObj,
      "draft",
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Boolean.to_js_boolean(v),
          getFromItems(madeObj, "draft"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~items: array(typeItems),
      ~onGroup: 'any_rki2=?,
      ~itemComponent: 'any_r0ad,
      ~containerComponent: 'any_rhia,
      ~emptyMessageComponent: 'any_rz4u,
      ~draggingEnabled: Js.boolean=?,
      ~isColumnGroupingEnabled: 'any_r3cd=?,
      ~onGroupDraft: 'any_roef=?,
      ~onGroupDraftCancel: 'any_rwl7=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "GroupPanelLayout";
  let make =
      (
        ~items: array(typeItems),
        ~onGroup: option('any_rki2)=?,
        ~itemComponent: 'any_r0ad,
        ~containerComponent: 'any_rhia,
        ~emptyMessageComponent: 'any_rz4u,
        ~draggingEnabled: option(bool)=?,
        ~isColumnGroupingEnabled: option('any_r3cd)=?,
        ~onGroupDraft: option('any_roef)=?,
        ~onGroupDraftCancel: option('any_rwl7)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~items=
            Js.Array.map(item => toJsUnsafe(convertItems(item)), items),
          ~onGroup?,
          ~itemComponent,
          ~containerComponent,
          ~emptyMessageComponent,
          ~draggingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              draggingEnabled,
            ),
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
  type r5u9 = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~groupByColumn: string=?, unit) => typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "groupByColumn",
        toJsUnsafe(getFromMessages(madeObj, "groupByColumn")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: Js.boolean=?,
      ~showGroupingControls: Js.boolean=?,
      ~layoutComponent: 'any_rlm1=?,
      ~containerComponent: 'any_r9f4=?,
      ~itemComponent: 'any_rso7=?,
      ~emptyMessageComponent: 'any_rykb=?,
      ~messages: 'any_rfx3=?,
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
        ~layoutComponent: option('any_rlm1)=?,
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
                   "getCellValue": ('any_rm7a, string) => 'any_r7yl,
                 },
                 "draft": string,
               },
               "showGroupingControls": bool,
               "showSortingControls": bool,
               "groupingEnabled": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {. "direction": [ | `Any('any_rmtf) | `Enum(r5u9)]} => unit,
               "onGroup": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~emptyMessageComponent:
           option(
             {. "getMessage": string => string} => ReasonReact.reactElement,
           )=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~showSortingControls=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showSortingControls,
            ),
          ~showGroupingControls=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showGroupingControls,
            ),
          ~layoutComponent?,
          ~containerComponent?,
          ~itemComponent?,
          ~emptyMessageComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module GroupingState = {
  type typeGrouping;
  [@bs.obj]
  external makeGrouping : (~columnName: string, unit) => typeGrouping = "";
  [@bs.get_index] external getFromGrouping : (typeGrouping, string) => 'a = "";
  let convertGrouping = (madeObj: typeGrouping) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromGrouping(madeObj, "columnName")),
    );
    returnObj;
  };
  type typeDefaultGrouping;
  [@bs.obj]
  external makeDefaultGrouping :
    (~columnName: string, unit) => typeDefaultGrouping =
    "";
  [@bs.get_index]
  external getFromDefaultGrouping : (typeDefaultGrouping, string) => 'a = "";
  let convertDefaultGrouping = (madeObj: typeDefaultGrouping) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromDefaultGrouping(madeObj, "columnName")),
    );
    returnObj;
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~groupingEnabled: Js.boolean, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "groupingEnabled",
      toJsUnsafe(
        Js.Boolean.to_js_boolean(
          getFromColumnExtensions(madeObj, "groupingEnabled"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~grouping: array(typeGrouping)=?,
      ~defaultGrouping: array(typeDefaultGrouping)=?,
      ~onGroupingChange: 'any_rjcy=?,
      ~expandedGroups: 'invalidArrayType_rdt6=?,
      ~defaultExpandedGroups: 'invalidArrayType_rfui=?,
      ~onExpandedGroupsChange: 'any_r1cn=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnGroupingEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "GroupingState";
  let make =
      (
        ~grouping: option(array(typeGrouping))=?,
        ~defaultGrouping: option(array(typeDefaultGrouping))=?,
        ~onGroupingChange: option(array(typeGrouping) => unit)=?,
        ~expandedGroups: option('invalidArrayType_rdt6)=?,
        ~defaultExpandedGroups: option('invalidArrayType_rfui)=?,
        ~onExpandedGroupsChange: option('invalidArrayType_recz => unit)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~columnGroupingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~grouping=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertGrouping(item)), v),
              grouping,
            ),
          ~defaultGrouping=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDefaultGrouping(item)),
                  v,
                ),
              defaultGrouping,
            ),
          ~onGroupingChange?,
          ~expandedGroups?,
          ~defaultExpandedGroups?,
          ~onExpandedGroupsChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnGroupingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnGroupingEnabled,
            ),
          (),
        ),
      children,
    );
};

module IntegratedFiltering = {
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~predicate: 'any_rj88=?, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "predicate",
      toJsUnsafe(getFromColumnExtensions(madeObj, "predicate")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (~columnExtensions: array(typeColumnExtensions)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedFiltering";
  let make =
      (~columnExtensions: option(array(typeColumnExtensions))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          (),
        ),
      children,
    );
};

module IntegratedGrouping = {
  type typeCriteriaReturn;
  [@bs.obj]
  external makeCriteriaReturn :
    (~key: 'union_ru00, ~value: 'any_ruff=?, unit) => typeCriteriaReturn =
    "";
  [@bs.get_index]
  external getFromCriteriaReturn : (typeCriteriaReturn, string) => 'a = "";
  let convertCriteriaReturn = (madeObj: typeCriteriaReturn) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "key",
      toJsUnsafe(unwrapValue(getFromCriteriaReturn(madeObj, "key"))),
    );
    Js.Dict.set(
      returnObj,
      "value",
      toJsUnsafe(getFromCriteriaReturn(madeObj, "value")),
    );
    returnObj;
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~criteria: 'any_rxm7=?, unit) => typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "criteria",
      toJsUnsafe(getFromColumnExtensions(madeObj, "criteria")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (~columnExtensions: array(typeColumnExtensions)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedGrouping";
  let make =
      (~columnExtensions: option(array(typeColumnExtensions))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
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
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~compare: 'any_rw4i=?, unit) => typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "compare",
      toJsUnsafe(getFromColumnExtensions(madeObj, "compare")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (~columnExtensions: array(typeColumnExtensions)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedSorting";
  let make =
      (~columnExtensions: option(array(typeColumnExtensions))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          (),
        ),
      children,
    );
};

module PagingPanel = {
  type typeMessages;
  [@bs.obj]
  external makeMessages :
    (~showAll: string=?, ~rowsPerPage: string=?, ~info: 'any_rh3m=?, unit) =>
    typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "showAll",
        toJsUnsafe(getFromMessages(madeObj, "showAll")),
      );
      Js.Dict.set(
        returnObj,
        "rowsPerPage",
        toJsUnsafe(getFromMessages(madeObj, "rowsPerPage")),
      );
      Js.Dict.set(
        returnObj,
        "info",
        toJsUnsafe(getFromMessages(madeObj, "info")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~pageSizes: 'arrayOf_riym=?,
      ~containerComponent: 'any_rmdp=?,
      ~messages: 'any_rfou=?,
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
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~pageSizes?,
          ~containerComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module PagingState = {
  [@bs.obj]
  external makeProps :
    (
      ~pageSize: 'number_s=?,
      ~defaultPageSize: 'number_n=?,
      ~onPageSizeChange: 'any_rmwb=?,
      ~currentPage: 'number_n=?,
      ~defaultCurrentPage: 'number_f=?,
      ~onCurrentPageChange: 'any_rhxo=?,
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
      ~onExpandedRowIdsChange: 'any_rjrf=?,
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
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~searchPlaceholder: string=?, unit) => typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "searchPlaceholder",
        toJsUnsafe(getFromMessages(madeObj, "searchPlaceholder")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (~inputComponent: 'any_rt78=?, ~messages: 'any_r5ky=?, unit) => _ =
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
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~inputComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module SearchState = {
  [@bs.obj]
  external makeProps :
    (
      ~value: string=?,
      ~defaultValue: string=?,
      ~onValueChange: 'any_rfd0=?,
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
      ~onSelectionChange: 'any_raq3=?,
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
  type typeSorting;
  [@bs.obj]
  external makeSorting :
    (~columnName: string, ~direction: direction, unit) => typeSorting =
    "";
  [@bs.get_index] external getFromSorting : (typeSorting, string) => 'a = "";
  let convertSorting = (madeObj: typeSorting) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromSorting(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "direction",
      toJsUnsafe(directionToJs(getFromSorting(madeObj, "direction"))),
    );
    returnObj;
  };
  type typeDefaultSorting;
  [@bs.obj]
  external makeDefaultSorting :
    (~columnName: string, ~direction: direction, unit) => typeDefaultSorting =
    "";
  [@bs.get_index]
  external getFromDefaultSorting : (typeDefaultSorting, string) => 'a = "";
  let convertDefaultSorting = (madeObj: typeDefaultSorting) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromDefaultSorting(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "direction",
      toJsUnsafe(
        directionToJs(getFromDefaultSorting(madeObj, "direction")),
      ),
    );
    returnObj;
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~sortingEnabled: Js.boolean, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "sortingEnabled",
      toJsUnsafe(
        Js.Boolean.to_js_boolean(
          getFromColumnExtensions(madeObj, "sortingEnabled"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~sorting: array(typeSorting)=?,
      ~defaultSorting: array(typeDefaultSorting)=?,
      ~onSortingChange: 'any_rz46=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnSortingEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SortingState";
  let make =
      (
        ~sorting: option(array(typeSorting))=?,
        ~defaultSorting: option(array(typeDefaultSorting))=?,
        ~onSortingChange: option(array(typeSorting) => unit)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~columnSortingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~sorting=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertSorting(item)), v),
              sorting,
            ),
          ~defaultSorting=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDefaultSorting(item)),
                  v,
                ),
              defaultSorting,
            ),
          ~onSortingChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnSortingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnSortingEnabled,
            ),
          (),
        ),
      children,
    );
};

module StaticTableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~headerRows: array('any_roh7)=?,
      ~rows: array('any_rf5j),
      ~columns: array('any_riuy),
      ~minWidth: 'number_5,
      ~containerComponent: 'any_rtd6,
      ~tableComponent: 'any_r770,
      ~headComponent: 'any_rarf=?,
      ~bodyComponent: 'any_r9z9,
      ~rowComponent: 'any_rr76,
      ~cellComponent: 'any_rnue,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "StaticTableLayout";
  let make =
      (
        ~headerRows: option(array('any_roh7))=?,
        ~rows: array('any_rf5j),
        ~columns: array('any_riuy),
        ~minWidth: [ | `Int(int) | `Float(float)],
        ~containerComponent: 'any_rtd6,
        ~tableComponent: 'any_r770,
        ~headComponent: option('any_rarf)=?,
        ~bodyComponent: 'any_r9z9,
        ~rowComponent: 'any_rr76,
        ~cellComponent: 'any_rnue,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~headerRows?,
          ~rows,
          ~columns,
          ~minWidth=unwrapValue(minWidth),
          ~containerComponent,
          ~tableComponent,
          ~headComponent?,
          ~bodyComponent,
          ~rowComponent,
          ~cellComponent,
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
      ~onOrderChange: 'any_rbjn=?,
      ~tableContainerComponent: 'any_rt7e=?,
      ~rowComponent: 'any_ry1p=?,
      ~cellComponent: 'any_rann=?,
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
        ~tableContainerComponent: option('any_rt7e)=?,
        ~rowComponent: option('any_ry1p)=?,
        ~cellComponent: option('any_rann)=?,
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
  type typeDefaultColumnWidths;
  [@bs.obj]
  external makeDefaultColumnWidths :
    (~columnName: string, ~width: 'number_0, unit) => typeDefaultColumnWidths =
    "";
  [@bs.get_index]
  external getFromDefaultColumnWidths : (typeDefaultColumnWidths, string) => 'a =
    "";
  let convertDefaultColumnWidths = (madeObj: typeDefaultColumnWidths) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromDefaultColumnWidths(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "width",
      toJsUnsafe(unwrapValue(getFromDefaultColumnWidths(madeObj, "width"))),
    );
    returnObj;
  };
  type typeColumnWidths;
  [@bs.obj]
  external makeColumnWidths :
    (~columnName: string, ~width: 'number_o, unit) => typeColumnWidths =
    "";
  [@bs.get_index]
  external getFromColumnWidths : (typeColumnWidths, string) => 'a = "";
  let convertColumnWidths = (madeObj: typeColumnWidths) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnWidths(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "width",
      toJsUnsafe(unwrapValue(getFromColumnWidths(madeObj, "width"))),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~defaultColumnWidths: array(typeDefaultColumnWidths)=?,
      ~columnWidths: array(typeColumnWidths)=?,
      ~onColumnWidthsChange: 'any_re1a=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableColumnResizing";
  let make =
      (
        ~defaultColumnWidths: option(array(typeDefaultColumnWidths))=?,
        ~columnWidths: option(array(typeColumnWidths))=?,
        ~onColumnWidthsChange: option(Js.t({..}) => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~defaultColumnWidths=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDefaultColumnWidths(item)),
                  v,
                ),
              defaultColumnWidths,
            ),
          ~columnWidths=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnWidths(item)),
                  v,
                ),
              columnWidths,
            ),
          ~onColumnWidthsChange?,
          (),
        ),
      children,
    );
};

module TableColumnVisibility = {
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~noColumns: string=?, unit) => typeMessages = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "noColumns",
        toJsUnsafe(getFromMessages(madeObj, "noColumns")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~togglingEnabled: Js.boolean, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "togglingEnabled",
      toJsUnsafe(
        Js.Boolean.to_js_boolean(
          getFromColumnExtensions(madeObj, "togglingEnabled"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~hiddenColumnNames: array(string)=?,
      ~defaultHiddenColumnNames: array(string)=?,
      ~emptyMessageComponent: 'any_r0ie=?,
      ~onHiddenColumnNamesChange: 'any_rbh5=?,
      ~messages: 'any_ryck=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnTogglingEnabled: Js.boolean=?,
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
        ~messages: option(typeMessages)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
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
          ~messages=?convertMessages(messages),
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnTogglingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnTogglingEnabled,
            ),
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
  type typeMessages;
  [@bs.obj]
  external makeMessages :
    (
      ~addCommand: string=?,
      ~editCommand: string=?,
      ~deleteCommand: string=?,
      ~commitCommand: string=?,
      ~cancelCommand: string=?,
      unit
    ) =>
    typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "addCommand",
        toJsUnsafe(getFromMessages(madeObj, "addCommand")),
      );
      Js.Dict.set(
        returnObj,
        "editCommand",
        toJsUnsafe(getFromMessages(madeObj, "editCommand")),
      );
      Js.Dict.set(
        returnObj,
        "deleteCommand",
        toJsUnsafe(getFromMessages(madeObj, "deleteCommand")),
      );
      Js.Dict.set(
        returnObj,
        "commitCommand",
        toJsUnsafe(getFromMessages(madeObj, "commitCommand")),
      );
      Js.Dict.set(
        returnObj,
        "cancelCommand",
        toJsUnsafe(getFromMessages(madeObj, "cancelCommand")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rqy5=?,
      ~headerCellComponent: 'any_rc93=?,
      ~commandComponent: 'any_r30r=?,
      ~showAddCommand: Js.boolean=?,
      ~showEditCommand: Js.boolean=?,
      ~showDeleteCommand: Js.boolean=?,
      ~width: 'union_rg22=?,
      ~messages: 'any_r3oc=?,
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
                 "row": 'any_rb2g,
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
                   "getCellValue": ('any_r4gn, string) => 'any_rycw,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_riun,
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
                 "row": 'any_r7qr,
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
                   "getCellValue": ('any_resj, string) => 'any_rm3r,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
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
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~cellComponent?,
          ~headerCellComponent?,
          ~commandComponent?,
          ~showAddCommand=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showAddCommand,
            ),
          ~showEditCommand=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showEditCommand,
            ),
          ~showDeleteCommand=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showDeleteCommand,
            ),
          ~width=?Js.Option.map((. v) => unwrapValue(v), width),
          ~messages=?convertMessages(messages),
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
      ~rowHeight: 'number_k=?,
      ~cellComponent: 'any_rftj=?,
      ~rowComponent: 'any_r7l4=?,
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
                 "row": 'any_ruoj,
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
                   "getCellValue": ('any_rqgd, string) => 'any_rlef,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rzxf,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rpgj, string) => 'any_rxvw,
               },
               "value": 'any_rbp7,
               "editingEnabled": bool,
               "onValueChange": 'any_r3zf => unit,
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
                 "row": 'any_r5w0,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_rjnt,
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
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~filterPlaceholder: string=?, unit) => typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "filterPlaceholder",
        toJsUnsafe(getFromMessages(madeObj, "filterPlaceholder")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_z=?,
      ~messages: 'any_r4c2=?,
      ~cellComponent: 'any_rexz=?,
      ~rowComponent: 'any_rb80=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableFilterRow";
  let make =
      (
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~messages: option(typeMessages)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_ra61,
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
                   "getCellValue": ('any_r7gx, string) => 'any_r9io,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
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
                 "getCellValue": ('any_rjd6, string) => 'any_rxct,
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
          ~messages=?convertMessages(messages),
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
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~showWhenGrouped: Js.boolean=?, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "showWhenGrouped",
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Boolean.to_js_boolean(v),
          getFromColumnExtensions(madeObj, "showWhenGrouped"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rvdg=?,
      ~rowComponent: 'any_rak3=?,
      ~indentCellComponent: 'any_r1e7=?,
      ~indentColumnWidth: 'number_z=?,
      ~showColumnsWhenGrouped: Js.boolean=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
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
                 "row": 'any_rjbg,
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
                   "getCellValue": ('any_recq, string) => 'any_rvjz,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rgeg,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rfo2, string) => 'any_rzhb,
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
                 "row": 'any_rqhu,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rk8v,
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
                 "row": 'any_rg7e,
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
                   "getCellValue": ('any_rwck, string) => 'any_r3t2,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rqax,
               },
               "column": 'any_ro3g,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~showColumnsWhenGrouped: option(bool)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
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
          ~showColumnsWhenGrouped=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showColumnsWhenGrouped,
            ),
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
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
  type rkn6 = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~sortingHint: string=?, unit) => typeMessages = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "sortingHint",
        toJsUnsafe(getFromMessages(madeObj, "sortingHint")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: Js.boolean=?,
      ~showGroupingControls: Js.boolean=?,
      ~cellComponent: 'any_r7q4=?,
      ~rowComponent: 'any_rkqq=?,
      ~messages: 'any_riec=?,
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
                 "row": 'any_r0u7,
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
                   "getCellValue": ('any_re3p, string) => 'any_r36q,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rvjp, string) => 'any_rang,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r1xb) | `Enum(rkn6)],
                   "keepOther": bool,
                 } =>
                 unit,
               "showGroupingControls": bool,
               "groupingEnabled": bool,
               "onGroup": unit => unit,
               "resizingEnabled": bool,
               "onWidthChange": 'any_rz4s => unit,
               "onWidthDraft": 'any_r0o0 => unit,
               "onWidthDraftCancel": unit => unit,
               "draggingEnabled": bool,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~showSortingControls=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showSortingControls,
            ),
          ~showGroupingControls=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showGroupingControls,
            ),
          ~cellComponent?,
          ~rowComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module TableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~columns: array('any_ridx),
      ~minColumnWidth: 'number_7,
      ~layoutComponent: 'any_ru3w,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableLayout";
  let make =
      (
        ~columns: array('any_ridx),
        ~minColumnWidth: [ | `Int(int) | `Float(float)],
        ~layoutComponent: 'any_ru3w,
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
      ~contentComponent: 'any_revi=?,
      ~toggleCellComponent: 'any_rfif=?,
      ~cellComponent: 'any_rsku=?,
      ~rowComponent: 'any_rpn6=?,
      ~toggleColumnWidth: 'number_5=?,
      ~rowHeight: 'number_1=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_rfxd} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rdkw,
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
                   "getCellValue": ('any_rbga, string) => 'any_r2uf,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rcpz,
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
                 "row": 'any_r33q,
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
                   "getCellValue": ('any_r47u, string) => 'any_r8sw,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r1vw,
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
                 "row": 'any_rs99,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_r4fl,
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
      ~headerCellComponent: 'any_rqtl=?,
      ~cellComponent: 'any_rx1c=?,
      ~rowComponent: 'any_r5k8=?,
      ~highlightRow: Js.boolean=?,
      ~selectByRowClick: Js.boolean=?,
      ~showSelectAll: Js.boolean=?,
      ~showSelectionColumn: Js.boolean=?,
      ~selectionColumnWidth: 'number_d=?,
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
                 "row": 'any_ral3,
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
                   "getCellValue": ('any_rzq9, string) => 'any_rfzt,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
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
                 "row": 'any_rsa8,
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
                   "getCellValue": ('any_rc5p, string) => 'any_rrs4,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rm60,
               "selected": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option('any_r5k8)=?,
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
          ~highlightRow=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              highlightRow,
            ),
          ~selectByRowClick=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              selectByRowClick,
            ),
          ~showSelectAll=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showSelectAll,
            ),
          ~showSelectionColumn=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showSelectionColumn,
            ),
          ~selectionColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), selectionColumnWidth),
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
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~width: 'number_t=?, ~align: align=?, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "width",
      toJsUnsafe(
        Js.Option.map(
          (. v) => unwrapValue(v),
          getFromColumnExtensions(madeObj, "width"),
        ),
      ),
    );
    Js.Dict.set(
      returnObj,
      "align",
      toJsUnsafe(
        Js.Option.map(
          (. v) => alignToJs(v),
          getFromColumnExtensions(madeObj, "align"),
        ),
      ),
    );
    returnObj;
  };
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~noData: string=?, unit) => typeMessages = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "noData",
        toJsUnsafe(getFromMessages(madeObj, "noData")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~layoutComponent: 'any_rbof=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_rji7=?,
      ~rowComponent: 'any_rn2v=?,
      ~noDataCellComponent: 'any_ro96=?,
      ~noDataRowComponent: 'any_rgyj=?,
      ~stubCellComponent: 'any_r05c=?,
      ~stubHeaderCellComponent: 'any_rrnv=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~messages: 'any_r6a2=?,
      ~fixedHeaderComponent: 'any_riif=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "Table";
  let make =
      (
        ~layoutComponent: option('any_rbof)=?,
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
                 "row": 'any_r0mw,
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
                   "getCellValue": ('any_rax8, string) => 'any_rrw9,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rz7h,
               "row": 'any_rfla,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rcsn, string) => 'any_rw3d,
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
                 "row": 'any_r10c,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_rnd4,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~noDataCellComponent:
           option(
             {. "getMessage": string => string} => ReasonReact.reactElement,
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
                 "row": 'any_rm63,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
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
                 "row": 'any_rale,
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
                   "getCellValue": ('any_rq0w, string) => 'any_r8j5,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
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
                 "row": 'any_r7y8,
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
                   "getCellValue": ('any_rakd, string) => 'any_rle5,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~messages: option(typeMessages)=?,
        ~fixedHeaderComponent: option('any_riif)=?,
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
          ~stubCellComponent?,
          ~stubHeaderCellComponent?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~messages=?convertMessages(messages),
          ~fixedHeaderComponent?,
          (),
        ),
      children,
    );
};

module Toolbar = {
  [@bs.obj]
  external makeProps :
    (
      ~rootComponent: 'any_rt69=?,
      ~flexibleSpaceComponent: 'any_rusp=?,
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
        ~flexibleSpaceComponent: option('any_rusp)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~rootComponent?, ~flexibleSpaceComponent?, ()),
      children,
    );
};

module VirtualTableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~minWidth: 'number_s,
      ~height: 'number_a,
      ~headerRows: array('any_rmsk)=?,
      ~rows: array('any_rcr3),
      ~columns: array('any_rk9o),
      ~cellComponent: 'any_rayt,
      ~rowComponent: 'any_ring,
      ~bodyComponent: 'any_r01q,
      ~headComponent: 'any_r3t1=?,
      ~tableComponent: 'any_ri65,
      ~headTableComponent: 'any_ro23=?,
      ~containerComponent: 'any_rogq,
      ~estimatedRowHeight: 'number_p,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "VirtualTableLayout";
  let make =
      (
        ~minWidth: [ | `Int(int) | `Float(float)],
        ~height: [ | `Int(int) | `Float(float)],
        ~headerRows: option(array('any_rmsk))=?,
        ~rows: array('any_rcr3),
        ~columns: array('any_rk9o),
        ~cellComponent: 'any_rayt,
        ~rowComponent: 'any_ring,
        ~bodyComponent: 'any_r01q,
        ~headComponent: option('any_r3t1)=?,
        ~tableComponent: 'any_ri65,
        ~headTableComponent: option('any_ro23)=?,
        ~containerComponent: 'any_rogq,
        ~estimatedRowHeight: [ | `Int(int) | `Float(float)],
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~minWidth=unwrapValue(minWidth),
          ~height=unwrapValue(height),
          ~headerRows?,
          ~rows,
          ~columns,
          ~cellComponent,
          ~rowComponent,
          ~bodyComponent,
          ~headComponent?,
          ~tableComponent,
          ~headTableComponent?,
          ~containerComponent,
          ~estimatedRowHeight=unwrapValue(estimatedRowHeight),
          (),
        ),
      children,
    );
};
