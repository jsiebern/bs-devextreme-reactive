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
      ~overlayComponent: 'any_r3ix=?,
      ~containerComponent: 'any_r319=?,
      ~itemComponent: 'any_relv=?,
      ~toggleButtonComponent: 'any_rp16=?,
      ~messages: 'any_rw6q=?,
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
               "target": 'any_r49f,
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
                   "getCellValue": ('any_rdqm, string) => 'any_rdjj,
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
               "buttonRef": 'any_rodc => unit,
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
    (~containerComponent: 'any_r323=?, ~columnComponent: 'any_req0=?, unit) =>
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
                 "getCellValue": ('any_rxox, string) => 'any_r4y7,
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
    type t('any_rghw, 'any_rseo) = {
      name: string,
      [@bs.optional]
      title: string,
      [@bs.optional]
      getCellValue: ('any_rghw, string) => 'any_rseo,
    };
    let make = t;
    let unwrap = (obj: t('any_rghw, 'any_rseo)) => {
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
      ~rows: array('any_rcxn)=?,
      ~getRowId: 'any_rrg7=?,
      ~getCellValue: 'any_rrqv=?,
      ~columns: array(Columns.t('any_rghw, 'any_rseo))=?,
      ~rootComponent: 'any_re6t=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_rcxn))=?,
        ~getRowId:
           option(
             'any_rpss => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_rcfl, string) => 'any_ry55)=?,
        ~columns: option(array(Columns.t('any_rghw, 'any_rseo)))=?,
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
      ~containerComponent: 'any_rzz6=?,
      ~itemComponent: 'any_ruyw=?,
      ~emptyMessageComponent: 'any_r3ro=?,
      ~messages: 'any_rm8g=?,
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
                   "getCellValue": ('any_rmkv, string) => 'any_r3zi,
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
                   "direction": [ | `Any('any_rsux) | `Enum(direction_enum)],
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
      ~pageSizes: 'arrayOf_rzev=?,
      ~containerComponent: 'any_roew=?,
      ~messages: 'any_rvu2=?,
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
    (~inputComponent: 'any_r8ff=?, ~messages: 'any_r9f7=?, unit) => _ =
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
      ~columnBands: array('any_rp3m)=?,
      ~cellComponent: 'any_rupd=?,
      ~rowComponent: 'any_ro9v=?,
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
        ~columnBands: option(array('any_rp3m))=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rxyi,
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
                   "getCellValue": ('any_rdls, string) => 'any_ryx9,
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
      ~onOrderChange: 'any_reg1=?,
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
      ~onColumnWidthsChange: 'any_rdjl=?,
      ~minColumnWidth: 'number_q=?,
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
      ~emptyMessageComponent: 'any_r0ym=?,
      ~onHiddenColumnNamesChange: 'any_rjry=?,
      ~messages: 'any_rbjm=?,
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
      ~cellComponent: 'any_rhek=?,
      ~headerCellComponent: 'any_ra8q=?,
      ~commandComponent: 'any_rx9d=?,
      ~showAddCommand: bool=?,
      ~showEditCommand: bool=?,
      ~showDeleteCommand: bool=?,
      ~width: 'union_rjsx=?,
      ~messages: 'any_rj88=?,
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
                 "row": 'any_r60f,
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
                   "getCellValue": ('any_rj9p, string) => 'any_rdj5,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_risk,
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
                 "row": 'any_raqo,
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
                   "getCellValue": ('any_rsnz, string) => 'any_rqds,
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
      ~rowHeight: 'number_j=?,
      ~cellComponent: 'any_rcpq=?,
      ~rowComponent: 'any_rrhw=?,
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
                 "row": 'any_r7ka,
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
                   "getCellValue": ('any_rnar, string) => 'any_repy,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r7py,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r69g, string) => 'any_r963,
               },
               "value": 'any_r9bd,
               "editingEnabled": bool,
               "onValueChange": 'any_rt19 => unit,
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
                 "row": 'any_rmgg,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rtxb,
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
      ~rowHeight: 'number_c=?,
      ~showFilterSelector: bool=?,
      ~messages: 'any_r585=?,
      ~cellComponent: 'any_reqc=?,
      ~rowComponent: 'any_r45b=?,
      ~filterSelectorComponent: 'any_rvyh=?,
      ~iconComponent: 'any_rz0n=?,
      ~editorComponent: 'any_rg03=?,
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
                 "row": 'any_rui3,
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
                   "getCellValue": ('any_rto1, string) => 'any_rvwu,
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
                 "getCellValue": ('any_r5v8, string) => 'any_rhmu,
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
               "value": 'any_rhn0,
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
      ~cellComponent: 'any_ramj=?,
      ~rowComponent: 'any_rhsv=?,
      ~indentCellComponent: 'any_r6be=?,
      ~indentColumnWidth: 'number_8=?,
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
                 "row": 'any_rl4u,
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
                   "getCellValue": ('any_rnfv, string) => 'any_r8uv,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_r9b5,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_ry45, string) => 'any_rh3z,
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
                 "row": 'any_rckx,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rt7t,
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
                 "row": 'any_rr1h,
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
                   "getCellValue": ('any_rubx, string) => 'any_rkx8,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rha5,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rklq, string) => 'any_r6yw,
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
      ~cellComponent: 'any_r7t8=?,
      ~rowComponent: 'any_rnty=?,
      ~messages: 'any_rdi5=?,
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
                 "row": 'any_r9q6,
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
                   "getCellValue": ('any_r8ia, string) => 'any_ri7t,
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
                 "getCellValue": ('any_r8jn, string) => 'any_rlau,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r1a7) | `Enum(direction_enum)],
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
      ~contentComponent: 'any_rdhk=?,
      ~toggleCellComponent: 'any_r34t=?,
      ~cellComponent: 'any_rgfd=?,
      ~rowComponent: 'any_riq8=?,
      ~toggleColumnWidth: 'number_t=?,
      ~rowHeight: 'number_4=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_r48c} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_ry4j,
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
                   "getCellValue": ('any_r56b, string) => 'any_rbwl,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rh22,
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
                 "row": 'any_r6di,
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
                   "getCellValue": ('any_relx, string) => 'any_r899,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r5xw,
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
                 "row": 'any_r8ys,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_ronz,
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
      ~headerCellComponent: 'any_rva0=?,
      ~cellComponent: 'any_rjps=?,
      ~rowComponent: 'genericCallback=?,
      ~highlightRow: bool=?,
      ~selectByRowClick: bool=?,
      ~showSelectAll: bool=?,
      ~showSelectionColumn: bool=?,
      ~selectionColumnWidth: 'number_k=?,
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
                 "row": 'any_rwxd,
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
                   "getCellValue": ('any_rflj, string) => 'any_rhfr,
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
                 "row": 'any_rvfu,
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
                   "getCellValue": ('any_rspe, string) => 'any_rdux,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r9jm,
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
      ~_for: string=?,
      ~showSelectionControls: bool=?,
      ~showSelectAll: bool=?,
      ~cellComponent: 'any_r9i4=?,
      ~indentComponent: 'any_rsv5=?,
      ~expandButtonComponent: 'any_r7ad=?,
      ~checkboxComponent: 'any_rue3=?,
      ~contentComponent: 'any_ri0e=?,
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
                 "row": 'any_r7z1,
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
                   "getCellValue": ('any_rs8j, string) => 'any_ro51,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rq2k,
               "row": 'any_rxah,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r2y0, string) => 'any_r5jd,
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
          ~_for=?for_,
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
      ~cellComponent: 'any_rb0n=?,
      ~rowComponent: 'any_r4cw=?,
      ~noDataCellComponent: 'any_r7gt=?,
      ~noDataRowComponent: 'any_rsg7=?,
      ~stubRowComponent: 'any_r5ba=?,
      ~stubCellComponent: 'any_r9bq=?,
      ~stubHeaderCellComponent: 'any_r345=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~messages: 'any_r5nw=?,
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
                 "row": 'any_rde7,
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
                   "getCellValue": ('any_riem, string) => 'any_rf2n,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rcdk,
               "row": 'any_rby3,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rzrn, string) => 'any_r4i5,
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
                 "row": 'any_rzmy,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rsoz,
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
                 "row": 'any_rwav,
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
                   "getCellValue": ('any_rtj5, string) => 'any_rbll,
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
                 "row": 'any_rubr,
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
                 "row": 'any_rqvs,
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
                 "row": 'any_r0gn,
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
                   "getCellValue": ('any_r1xb, string) => 'any_r0tk,
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
                 "row": 'any_r570,
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
                   "getCellValue": ('any_ry49, string) => 'any_rxti,
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
      ~rootComponent: 'any_r4xc=?,
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
      ~estimatedRowHeight: 'number_m=?,
      ~height: 'number_9=?,
      ~headTableComponent: 'genericCallback=?,
      ~messages: 'any_rqub=?,
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
