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
      ~overlayComponent: 'any_rfne=?,
      ~containerComponent: 'any_rnbr=?,
      ~itemComponent: 'any_ries=?,
      ~toggleButtonComponent: 'any_r7vo=?,
      ~messages: 'any_rp6g=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "ColumnChooser";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_rp8g,
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
                   "getCellValue": ('any_rnrc, string) => 'any_rzmw,
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
               "buttonRef": 'any_r4ub => unit,
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

module DragDropProvider = {
  [@bs.obj]
  external makeProps :
    (~containerComponent: 'any_rdmw=?, ~columnComponent: 'any_rpof=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "getCellValue": ('any_rsig, string) => 'any_rn7t,
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

module Grid = {
  type typeColumns;
  [@bs.obj]
  external makeColumns :
    (~name: string, ~title: string=?, ~getCellValue: 'any_rhlr=?, unit) =>
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
      ~rows: array('any_rugv)=?,
      ~getRowId: 'any_rugb=?,
      ~getCellValue: 'any_rb43=?,
      ~columns: array(typeColumns)=?,
      ~rootComponent: 'any_rbw3=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_rugv))=?,
        ~getRowId:
           option(
             'any_r8em => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_rrv9, string) => 'any_r7z8)=?,
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

module GroupingPanel = {
  [@bs.deriving jsConverter]
  type sortingDirection = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  [@bs.deriving jsConverter]
  type rhf7 = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
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
      ~layoutComponent: 'any_rfkn=?,
      ~containerComponent: 'any_r2s2=?,
      ~itemComponent: 'any_rtn1=?,
      ~emptyMessageComponent: 'any_rf45=?,
      ~messages: 'any_rj5n=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "GroupingPanel";
  let make =
      (
        ~showSortingControls: option(bool)=?,
        ~showGroupingControls: option(bool)=?,
        ~layoutComponent: option('any_rfkn)=?,
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
                   "getCellValue": ('any_rjdv, string) => 'any_rj8t,
                 },
                 "draft": string,
               },
               "showGroupingControls": bool,
               "showSortingControls": bool,
               "groupingEnabled": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {. "direction": [ | `Any('any_rtkq) | `Enum(rhf7)]} => unit,
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

module PagingPanel = {
  type typeMessages;
  [@bs.obj]
  external makeMessages :
    (~showAll: string=?, ~rowsPerPage: string=?, ~info: 'any_roxm=?, unit) =>
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
      ~pageSizes: 'arrayOf_rjby=?,
      ~containerComponent: 'any_rkaa=?,
      ~messages: 'any_rcoy=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
    (~inputComponent: 'any_rp2r=?, ~messages: 'any_r0pd=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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

module TableColumnReordering = {
  [@bs.obj]
  external makeProps :
    (
      ~order: array(string)=?,
      ~defaultOrder: array(string)=?,
      ~onOrderChange: 'any_rpzk=?,
      ~tableContainerComponent: 'any_r6zb=?,
      ~rowComponent: 'any_rqa0=?,
      ~cellComponent: 'any_ri4c=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "TableColumnReordering";
  let make =
      (
        ~order: option(array(string))=?,
        ~defaultOrder: option(array(string))=?,
        ~onOrderChange: option(array(string) => unit)=?,
        ~tableContainerComponent: option('any_r6zb)=?,
        ~rowComponent: option('any_rqa0)=?,
        ~cellComponent: option('any_ri4c)=?,
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
    (~columnName: string, ~width: 'number_w, unit) => typeDefaultColumnWidths =
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
    (~columnName: string, ~width: 'number_3, unit) => typeColumnWidths =
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
      ~onColumnWidthsChange: 'any_rrqv=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
      ~emptyMessageComponent: 'any_rkty=?,
      ~onHiddenColumnNamesChange: 'any_rujn=?,
      ~messages: 'any_rrnq=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnTogglingEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
      ~cellComponent: 'any_res5=?,
      ~headerCellComponent: 'any_rsmy=?,
      ~commandComponent: 'any_rz2e=?,
      ~showAddCommand: Js.boolean=?,
      ~showEditCommand: Js.boolean=?,
      ~showDeleteCommand: Js.boolean=?,
      ~width: 'union_rhcf=?,
      ~messages: 'any_r19r=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_rka8,
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
                   "getCellValue": ('any_r7l6, string) => 'any_rzwq,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r8y4,
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
                 "row": 'any_rhd0,
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
                   "getCellValue": ('any_rebe, string) => 'any_r01j,
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
      ~rowHeight: 'number_d=?,
      ~cellComponent: 'any_rm3t=?,
      ~rowComponent: 'any_rm7o=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_rgex,
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
                   "getCellValue": ('any_rycv, string) => 'any_r1rw,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_ryz5,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rug0, string) => 'any_r1jq,
               },
               "value": 'any_rfm2,
               "editingEnabled": bool,
               "onValueChange": 'any_r0hc => unit,
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
                 "row": 'any_r3dk,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_reps,
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
      ~rowHeight: 'number_k=?,
      ~messages: 'any_rxuc=?,
      ~cellComponent: 'any_rbyr=?,
      ~rowComponent: 'any_rfq2=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_rbbq,
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
                   "getCellValue": ('any_r2c0, string) => 'any_rj7t,
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
                 "getCellValue": ('any_ryn4, string) => 'any_rfbw,
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
      ~cellComponent: 'any_reej=?,
      ~rowComponent: 'any_rl6k=?,
      ~indentCellComponent: 'any_rwnq=?,
      ~indentColumnWidth: 'number_b=?,
      ~showColumnsWhenGrouped: Js.boolean=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_rqxg,
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
                   "getCellValue": ('any_rwce, string) => 'any_r7t6,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_ri19,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_ruka, string) => 'any_rn30,
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
                 "row": 'any_r0dg,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_r4ih,
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
                 "row": 'any_r99l,
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
                   "getCellValue": ('any_ror6, string) => 'any_ri4s,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rj48,
               },
               "column": 'any_r4gw,
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
  type r90g = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
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
      ~cellComponent: 'any_rsde=?,
      ~rowComponent: 'any_rt0x=?,
      ~messages: 'any_rkih=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_rx5b,
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
                   "getCellValue": ('any_rvob, string) => 'any_r3f5,
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
                 "getCellValue": ('any_rljl, string) => 'any_rrqa,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_rej3) | `Enum(r90g)],
                   "keepOther": bool,
                 } =>
                 unit,
               "showGroupingControls": bool,
               "groupingEnabled": bool,
               "onGroup": unit => unit,
               "resizingEnabled": bool,
               "onWidthChange": 'any_rdp1 => unit,
               "onWidthDraft": 'any_rkrb => unit,
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
      ~contentComponent: 'any_r375=?,
      ~toggleCellComponent: 'any_rusi=?,
      ~cellComponent: 'any_rken=?,
      ~rowComponent: 'any_rs8i=?,
      ~toggleColumnWidth: 'number_i=?,
      ~rowHeight: 'number_l=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_re89} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rb62,
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
                   "getCellValue": ('any_rg78, string) => 'any_rrxm,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r4yb,
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
                 "row": 'any_r3tu,
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
                   "getCellValue": ('any_rddy, string) => 'any_rz3y,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r0n2,
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
                 "row": 'any_rsd0,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_r58c,
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
      ~headerCellComponent: 'any_r7c6=?,
      ~cellComponent: 'any_ruho=?,
      ~rowComponent: 'any_rvv1=?,
      ~highlightRow: Js.boolean=?,
      ~selectByRowClick: Js.boolean=?,
      ~showSelectAll: Js.boolean=?,
      ~showSelectionColumn: Js.boolean=?,
      ~selectionColumnWidth: 'number_2=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_r8yk,
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
                   "getCellValue": ('any_r2zx, string) => 'any_rjt5,
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
                 "row": 'any_rcw2,
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
                   "getCellValue": ('any_r8e4, string) => 'any_ry37,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rhg9,
               "selected": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option('any_rvv1)=?,
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
    (~columnName: string, ~width: 'number_0=?, ~align: align=?, unit) =>
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
      ~layoutComponent: 'any_rlmf=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_rutr=?,
      ~rowComponent: 'any_r5c0=?,
      ~noDataCellComponent: 'any_rj4i=?,
      ~noDataRowComponent: 'any_rhxt=?,
      ~stubCellComponent: 'any_ra8b=?,
      ~stubHeaderCellComponent: 'any_r0ws=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~messages: 'any_rbca=?,
      ~fixedHeaderComponent: 'any_rbch=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "Table";
  let make =
      (
        ~layoutComponent: option('any_rlmf)=?,
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
                 "row": 'any_rsew,
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
                   "getCellValue": ('any_ry3y, string) => 'any_ro5w,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rufo,
               "row": 'any_rlhv,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rbxk, string) => 'any_rrqi,
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
                 "row": 'any_r5h2,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_rot5,
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
                 "row": 'any_rugb,
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
                 "row": 'any_ru2z,
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
                   "getCellValue": ('any_r1pf, string) => 'any_r0e4,
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
                 "row": 'any_rho8,
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
                   "getCellValue": ('any_rs9o, string) => 'any_rgu3,
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
        ~fixedHeaderComponent: option('any_rbch)=?,
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
      ~rootComponent: 'any_rgdy=?,
      ~flexibleSpaceComponent: 'any_r2qj=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "Toolbar";
  let make =
      (
        ~rootComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~flexibleSpaceComponent: option('any_r2qj)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~rootComponent?, ~flexibleSpaceComponent?, ()),
      children,
    );
};

module VirtualTable = {
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
      ~estimatedRowHeight: 'number_y=?,
      ~height: 'number_0=?,
      ~messages: 'any_rtvy=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "VirtualTable";
  let make =
      (
        ~estimatedRowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~height: option([ | `Int(int) | `Float(float)])=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~estimatedRowHeight=?
            Js.Option.map((. v) => unwrapValue(v), estimatedRowHeight),
          ~height=?Js.Option.map((. v) => unwrapValue(v), height),
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};
