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
  | `Object(_) => assert false
  | `Enum(_) => assert false
  | `EnumArray(_) => assert false;

module ColumnChooser = {
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      showColumnChooser: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. showColumnChooser) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("showColumnChooser", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~overlayComponent: 'any_rca0=?,
      ~containerComponent: 'any_r5ph=?,
      ~itemComponent: 'any_riru=?,
      ~toggleButtonComponent: 'any_re2b=?,
      ~messages: 'any_r1si=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "ColumnChooser";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_roq1,
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
                   "getCellValue": ('any_r1wd, string) => 'any_rt1r,
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
               "buttonRef": 'any_rn74 => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj]
  external makeProps :
    (~containerComponent: 'any_r3bw=?, ~columnComponent: 'any_rt9a=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                 "getCellValue": ('any_r1la, string) => 'any_rxvj,
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
  module Columns = {
    [@bs.deriving abstract]
    type t('any_roc3, 'any_rrct) = {
      name: string,
      [@bs.optional]
      title: string,
      [@bs.optional]
      getCellValue: ('any_roc3, string) => 'any_rrct,
    };
    let make = t;
    let unwrap = (obj: t('any_roc3, 'any_rrct)) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap |. Js.Dict.set("name", obj |. name |. toJsUnsafe);
      switch (obj |. title) {
      | Some(v) => unwrappedMap |. Js.Dict.set("title", v |. toJsUnsafe)
      | None => ()
      };
      switch (obj |. getCellValue) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("getCellValue", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~rows: array('any_rfz0)=?,
      ~getRowId: 'any_retl=?,
      ~getCellValue: 'any_rutp=?,
      ~columns: array(Columns.t('any_roc3, 'any_rrct))=?,
      ~rootComponent: 'any_rq1t=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_rfz0))=?,
        ~getRowId:
           option(
             'any_ruxo => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_rvde, string) => 'any_rzhb)=?,
        ~columns: option(array(Columns.t('any_roc3, 'any_rrct)))=?,
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
                Js.Array.map(item => toJsUnsafe(Columns.unwrap(item)), v),
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
  type direction_enum = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      groupByColumn: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. groupByColumn) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("groupByColumn", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: bool=?,
      ~showGroupingControls: bool=?,
      ~layoutComponent: 'genericCallback=?,
      ~containerComponent: 'any_rn36=?,
      ~itemComponent: 'any_rgnn=?,
      ~emptyMessageComponent: 'any_rgdw=?,
      ~messages: 'any_rmbd=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                   "getCellValue": ('any_rws0, string) => 'any_rlbq,
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
                   "direction": [ | `Any('any_rsty) | `Enum(direction_enum)],
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
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};

module PagingPanel = {
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      showAll: string,
      [@bs.optional]
      rowsPerPage: string,
      [@bs.optional]
      info:
        {
          .
          "from": [ | `Int(int) | `Float(float)],
          "to": [ | `Int(int) | `Float(float)],
          "count": [ | `Int(int) | `Float(float)],
        } =>
        [ | `String(string) | `String(string)],
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. showAll) {
        | Some(v) => unwrappedMap |. Js.Dict.set("showAll", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. rowsPerPage) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("rowsPerPage", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. info) {
        | Some(v) => unwrappedMap |. Js.Dict.set("info", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~pageSizes: 'arrayOf_r081=?,
      ~containerComponent: 'any_red4=?,
      ~messages: 'any_r84k=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
        ~messages: option(Messages.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~pageSizes?,
          ~containerComponent?,
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};

module SearchPanel = {
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      searchPlaceholder: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. searchPlaceholder) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("searchPlaceholder", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (~inputComponent: 'any_rlz5=?, ~messages: 'any_r2ff=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
        ~messages: option(Messages.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~inputComponent?,
          ~messages=?Messages.unwrap(messages),
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
      ~columnBands: array('any_r9xr)=?,
      ~cellComponent: 'any_r6x3=?,
      ~rowComponent: 'any_r1dt=?,
      ~bandedHeaderCellComponent: 'genericCallback=?,
      ~invisibleCellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableBandHeader";
  let make =
      (
        ~columnBands: option(array('any_r9xr))=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_razt,
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
                   "getCellValue": ('any_r9o3, string) => 'any_rawn,
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
      ~onOrderChange: 'any_rcic=?,
      ~tableContainerComponent: 'genericCallback=?,
      ~rowComponent: 'genericCallback=?,
      ~cellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
  module DefaultColumnWidths = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      width: [ | `Int(int) | `Float(float)],
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("width", unwrapValue(obj |. width) |. toJsUnsafe);
      unwrappedMap;
    };
  };
  module ColumnWidths = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      width: [ | `Int(int) | `Float(float)],
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("width", unwrapValue(obj |. width) |. toJsUnsafe);
      unwrappedMap;
    };
  };
  module NextColumnWidths = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      width: [ | `Int(int) | `Float(float)],
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("width", unwrapValue(obj |. width) |. toJsUnsafe);
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~defaultColumnWidths: array(DefaultColumnWidths.t)=?,
      ~columnWidths: array(ColumnWidths.t)=?,
      ~onColumnWidthsChange: 'any_r46p=?,
      ~minColumnWidth: 'number_g=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableColumnResizing";
  let make =
      (
        ~defaultColumnWidths: option(array(DefaultColumnWidths.t))=?,
        ~columnWidths: option(array(ColumnWidths.t))=?,
        ~onColumnWidthsChange: option(array(NextColumnWidths.t) => unit)=?,
        ~minColumnWidth: option([ | `Int(int) | `Float(float)])=?,
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
                  item => toJsUnsafe(DefaultColumnWidths.unwrap(item)),
                  v,
                ),
              defaultColumnWidths,
            ),
          ~columnWidths=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnWidths.unwrap(item)),
                  v,
                ),
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      noColumns: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. noColumns) {
        | Some(v) => unwrappedMap |. Js.Dict.set("noColumns", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      togglingEnabled: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("togglingEnabled", obj |. togglingEnabled |. toJsUnsafe);
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~hiddenColumnNames: array(string)=?,
      ~defaultHiddenColumnNames: array(string)=?,
      ~emptyMessageComponent: 'any_re8g=?,
      ~onHiddenColumnNamesChange: 'any_r3dt=?,
      ~messages: 'any_rgah=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~columnTogglingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
        ~messages: option(Messages.t)=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
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
          ~messages=?Messages.unwrap(messages),
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
                  v,
                ),
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      addCommand: string,
      [@bs.optional]
      editCommand: string,
      [@bs.optional]
      deleteCommand: string,
      [@bs.optional]
      commitCommand: string,
      [@bs.optional]
      cancelCommand: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. addCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("addCommand", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. editCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("editCommand", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. deleteCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("deleteCommand", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. commitCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("commitCommand", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. cancelCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("cancelCommand", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_r85n=?,
      ~headerCellComponent: 'any_rd2a=?,
      ~commandComponent: 'any_r9mh=?,
      ~showAddCommand: bool=?,
      ~showEditCommand: bool=?,
      ~showDeleteCommand: bool=?,
      ~width: 'union_riuu=?,
      ~messages: 'any_romz=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                 "row": 'any_rrcn,
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
                   "getCellValue": ('any_rcil, string) => 'any_rb84,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rmka,
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
                 "row": 'any_r5da,
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
                   "getCellValue": ('any_rpae, string) => 'any_r7th,
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
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
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
      ~rowHeight: 'number_a=?,
      ~cellComponent: 'any_ruxm=?,
      ~rowComponent: 'any_rthd=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                 "row": 'any_r0g7,
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
                   "getCellValue": ('any_ral2, string) => 'any_rg6k,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rplo,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_reha, string) => 'any_rzn6,
               },
               "value": 'any_rvew,
               "editingEnabled": bool,
               "onValueChange": 'any_r67f => unit,
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
                 "row": 'any_ref9,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rq8k,
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      filterPlaceholder: string,
      [@bs.optional]
      contains: string,
      [@bs.optional]
      notContains: string,
      [@bs.optional]
      startsWith: string,
      [@bs.optional]
      endsWith: string,
      [@bs.optional]
      equal: string,
      [@bs.optional]
      notEqual: string,
      [@bs.optional]
      greaterThan: string,
      [@bs.optional]
      greaterThanOrEqual: string,
      [@bs.optional]
      lessThan: string,
      [@bs.optional]
      lessThanOrEqual: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. filterPlaceholder) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("filterPlaceholder", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. contains) {
        | Some(v) => unwrappedMap |. Js.Dict.set("contains", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. notContains) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("notContains", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. startsWith) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("startsWith", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. endsWith) {
        | Some(v) => unwrappedMap |. Js.Dict.set("endsWith", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. equal) {
        | Some(v) => unwrappedMap |. Js.Dict.set("equal", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. notEqual) {
        | Some(v) => unwrappedMap |. Js.Dict.set("notEqual", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. greaterThan) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("greaterThan", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. greaterThanOrEqual) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("greaterThanOrEqual", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. lessThan) {
        | Some(v) => unwrappedMap |. Js.Dict.set("lessThan", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. lessThanOrEqual) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("lessThanOrEqual", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
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
      ~rowHeight: 'number_l=?,
      ~showFilterSelector: bool=?,
      ~messages: 'any_rf5w=?,
      ~cellComponent: 'any_rfao=?,
      ~rowComponent: 'any_r5gd=?,
      ~filterSelectorComponent: 'any_rb0z=?,
      ~iconComponent: 'any_rgp1=?,
      ~editorComponent: 'any_rasr=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableFilterRow";
  let make =
      (
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~showFilterSelector: option(bool)=?,
        ~messages: option(Messages.t)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r1v2,
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
                   "getCellValue": ('any_rofq, string) => 'any_reg8,
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
                 "getCellValue": ('any_rpf9, string) => 'any_rsa2,
               },
               "filteringEnabled": bool,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        ~filterSelectorComponent:
           option(
             {
               .
               "iconComponent":
                 {. "type": string} => ReasonReact.reactElement,
               "value": string,
               "availableValues": array(string),
               "onChange": string => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~iconComponent:
           option({. "type": string} => ReasonReact.reactElement)=?,
        ~editorComponent:
           option(
             {
               .
               "value": 'any_r912,
               "disabled": bool,
               "onChange": string => unit,
               "getMessage": string => string,
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
          ~showFilterSelector?,
          ~messages=?Messages.unwrap(messages),
          ~cellComponent?,
          ~rowComponent?,
          ~filterSelectorComponent?,
          ~iconComponent?,
          ~editorComponent?,
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
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      [@bs.optional]
      showWhenGrouped: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (obj |. showWhenGrouped) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("showWhenGrouped", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rcfo=?,
      ~rowComponent: 'any_rm07=?,
      ~indentCellComponent: 'any_radz=?,
      ~indentColumnWidth: 'number_0=?,
      ~showColumnsWhenGrouped: bool=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                 "row": 'any_rw5i,
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
                   "getCellValue": ('any_rbp3, string) => 'any_rw66,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rir5,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rpni, string) => 'any_r33h,
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
                 "row": 'any_rnsd,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rd9h,
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
                 "row": 'any_rlwy,
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
                   "getCellValue": ('any_r8qh, string) => 'any_rv4e,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_r9x5,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_ro3i, string) => 'any_rqf7,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~showColumnsWhenGrouped: option(bool)=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
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
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
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
  type direction_enum = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      sortingHint: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. sortingHint) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("sortingHint", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: bool=?,
      ~showGroupingControls: bool=?,
      ~cellComponent: 'any_rrxi=?,
      ~rowComponent: 'any_r69c=?,
      ~messages: 'any_rtva=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                 "row": 'any_rm53,
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
                   "getCellValue": ('any_ro08, string) => 'any_r2ev,
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
                 "getCellValue": ('any_rswx, string) => 'any_r16e,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r6w4) | `Enum(direction_enum)],
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
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
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
      ~contentComponent: 'any_rntl=?,
      ~toggleCellComponent: 'any_r8y0=?,
      ~cellComponent: 'any_r4ap=?,
      ~rowComponent: 'any_rfi7=?,
      ~toggleColumnWidth: 'number_f=?,
      ~rowHeight: 'number_2=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_r834} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_ru9s,
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
                   "getCellValue": ('any_rlxy, string) => 'any_rgmp,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_ro42,
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
                 "row": 'any_ri8r,
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
                   "getCellValue": ('any_r0jp, string) => 'any_rylm,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rnnh,
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
                 "row": 'any_rg5e,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_r65k,
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
      ~headerCellComponent: 'any_rao5=?,
      ~cellComponent: 'any_r8ho=?,
      ~rowComponent: 'genericCallback=?,
      ~highlightRow: bool=?,
      ~selectByRowClick: bool=?,
      ~showSelectAll: bool=?,
      ~showSelectionColumn: bool=?,
      ~selectionColumnWidth: 'number_6=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                 "row": 'any_rgv6,
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
                   "getCellValue": ('any_rjgq, string) => 'any_rxpw,
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
                 "row": 'any_rh62,
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
                   "getCellValue": ('any_r5dz, string) => 'any_rl7z,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rnsy,
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
      ~cellComponent: 'any_rusy=?,
      ~indentComponent: 'any_rdl9=?,
      ~expandButtonComponent: 'any_ravr=?,
      ~checkboxComponent: 'any_r6pp=?,
      ~contentComponent: 'any_rqlu=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                 "row": 'any_ry2n,
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
                   "getCellValue": ('any_rypp, string) => 'any_rql5,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_r0rd,
               "row": 'any_ro86,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rk3s, string) => 'any_r1a6,
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
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      [@bs.optional]
      width: [ | `Int(int) | `Float(float)],
      [@bs.optional]
      align,
      [@bs.optional]
      wordWrapEnabled: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (Js.Option.map((. v) => unwrapValue(v), obj |. width)) {
      | Some(v) => unwrappedMap |. Js.Dict.set("width", v |. toJsUnsafe)
      | None => ()
      };
      switch (Js.Option.map((. v) => alignToJs(v), obj |. align)) {
      | Some(v) => unwrappedMap |. Js.Dict.set("align", v |. toJsUnsafe)
      | None => ()
      };
      switch (obj |. wordWrapEnabled) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("wordWrapEnabled", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      noData: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. noData) {
        | Some(v) => unwrappedMap |. Js.Dict.set("noData", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~layoutComponent: 'genericCallback=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_r37f=?,
      ~rowComponent: 'any_rx66=?,
      ~noDataCellComponent: 'any_rxvs=?,
      ~noDataRowComponent: 'any_rtw2=?,
      ~stubRowComponent: 'any_rfvl=?,
      ~stubCellComponent: 'any_rmq9=?,
      ~stubHeaderCellComponent: 'any_rxx3=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~messages: 'any_rv65=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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
                 "row": 'any_rcc8,
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
                   "getCellValue": ('any_r6lx, string) => 'any_r2hf,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rsaj,
               "row": 'any_roi2,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r4fr, string) => 'any_rbdy,
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
                 "row": 'any_rxuc,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rtdn,
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
                 "row": 'any_rm8y,
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
                   "getCellValue": ('any_r0by, string) => 'any_r4e7,
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
                 "row": 'any_rc9w,
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
                 "row": 'any_roh2,
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
                 "row": 'any_rjxn,
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
                   "getCellValue": ('any_r947, string) => 'any_r64h,
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
                 "row": 'any_r197,
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
                   "getCellValue": ('any_rhka, string) => 'any_r9ch,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
        ~messages: option(Messages.t)=?,
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
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};

module Toolbar = {
  [@bs.obj]
  external makeProps :
    (
      ~rootComponent: 'any_ruap=?,
      ~flexibleSpaceComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
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

module VirtualTable = {
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      noData: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. noData) {
        | Some(v) => unwrappedMap |. Js.Dict.set("noData", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~estimatedRowHeight: 'number_j=?,
      ~height: 'number_h=?,
      ~headTableComponent: 'genericCallback=?,
      ~messages: 'any_r4fo=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "VirtualTable";
  let make =
      (
        ~estimatedRowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~height: option([ | `Int(int) | `Float(float)])=?,
        ~headTableComponent: option('genericCallback)=?,
        ~messages: option(Messages.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~estimatedRowHeight=?
            Js.Option.map((. v) => unwrapValue(v), estimatedRowHeight),
          ~height=?Js.Option.map((. v) => unwrapValue(v), height),
          ~headTableComponent?,
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};
