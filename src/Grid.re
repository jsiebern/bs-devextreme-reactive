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
      ~overlayComponent: 'any_rois=?,
      ~containerComponent: 'any_rjh0=?,
      ~itemComponent: 'any_rn8j=?,
      ~toggleButtonComponent: 'any_r7sc=?,
      ~messages: 'any_rq3w=?,
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
               "target": 'any_rte2,
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
                   "getCellValue": ('any_r18u, string) => 'any_r9tn,
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
               "buttonRef": 'any_rnt9 => unit,
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

module CustomGrouping = {
  module Grouping = {
    [@bs.deriving abstract]
    type t = {columnName: string};
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~getChildGroups: 'any_r2v2,
      ~grouping: array(Grouping.t)=?,
      ~expandedGroups: 'invalidArrayType_rclq=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomGrouping";
  let make =
      (
        ~getChildGroups:
           (array('any_rwup), {. "columnName": string}, array('any_r55n)) =>
           array(array('any_rks5)),
        ~grouping: option(array(Grouping.t))=?,
        ~expandedGroups: option('invalidArrayType_rclq)=?,
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
                Js.Array.map(item => toJsUnsafe(Grouping.unwrap(item)), v),
              grouping,
            ),
          ~expandedGroups?,
          (),
        ),
      children,
    );
};

module CustomPaging = {
  [@bs.obj] external makeProps : (~totalCount: 'number_q=?, unit) => _ = "";
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
  [@bs.obj] external makeProps : (~getChildRows: 'any_rrhp, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomTreeData";
  let make =
      (
        ~getChildRows:
           ([ | `Any('any_r5xh) | `Any('any_r34z)], array('any_rci4)) =>
           array('any_rcdq),
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
      ~_for: array(string),
      ~formatterComponent: 'any_r00v=?,
      ~editorComponent: 'any_rb95=?,
      ~availableFilterOperations: array(string)=?,
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
                 "getCellValue": ('any_ryxm, string) => 'any_ru7l,
               },
               "row": 'any_r20p,
               "value": 'any_rttx,
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
                 "getCellValue": ('any_rl4e, string) => 'any_rnl4,
               },
               "row": 'any_r5iv,
               "value": 'any_r8yo,
               "onValueChange": 'any_rjqy => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~availableFilterOperations: option(array(string))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~_for=for_,
          ~formatterComponent?,
          ~editorComponent?,
          ~availableFilterOperations?,
          (),
        ),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj]
  external makeProps :
    (~containerComponent: 'any_r0wm=?, ~columnComponent: 'any_rsom=?, unit) =>
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
                 "getCellValue": ('any_rest, string) => 'any_r4ax,
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
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t('any_r03u, 'any_ro3w, 'any_rnha) = {
      columnName: string,
      [@bs.optional]
      editingEnabled: bool,
      [@bs.optional]
      createRowChange: ('any_r03u, 'any_ro3w, string) => 'any_rnha,
    };
    let make = t;
    let unwrap = (obj: t('any_r03u, 'any_ro3w, 'any_rnha)) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (obj |. editingEnabled) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("editingEnabled", v |. toJsUnsafe)
      | None => ()
      };
      switch (obj |. createRowChange) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("createRowChange", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  module Changes = {
    [@bs.deriving abstract]
    type t('any_rvcb, 'a) = {
      [@bs.optional]
      added: array('any_rvcb),
      [@bs.optional]
      changed: Js.t({..} as 'a),
      [@bs.optional]
      deleted: array([ | `Int(int) | `Float(float) | `String(string)]),
    };
    let make = t;
    let unwrap = (obj: t('any_rvcb, 'a)) => {
      let unwrappedMap = Js.Dict.empty();
      switch (
        Js.Option.map(
          (. v) => Js.Array.map(item => toJsUnsafe(item), v),
          obj |. added,
        )
      ) {
      | Some(v) => unwrappedMap |. Js.Dict.set("added", v |. toJsUnsafe)
      | None => ()
      };
      switch (obj |. changed) {
      | Some(v) => unwrappedMap |. Js.Dict.set("changed", v |. toJsUnsafe)
      | None => ()
      };
      switch (
        Js.Option.map(
          (. v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
          obj |. deleted,
        )
      ) {
      | Some(v) => unwrappedMap |. Js.Dict.set("deleted", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~createRowChange: 'any_r3cy=?,
      ~columnEditingEnabled: bool=?,
      ~columnExtensions: array(
                           ColumnExtensions.t(
                             'any_r03u,
                             'any_ro3w,
                             'any_rnha,
                           ),
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
      ~onEditingRowIdsChange: 'any_r0r8=?,
      ~addedRows: array('any_r5nx)=?,
      ~defaultAddedRows: array('any_re8c)=?,
      ~onAddedRowsChange: 'any_r43i=?,
      ~rowChanges: Js.t({..})=?,
      ~defaultRowChanges: Js.t({..})=?,
      ~onRowChangesChange: 'any_r0lq=?,
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
      ~onDeletedRowIdsChange: 'any_rj0y=?,
      ~onCommitChanges: 'any_rbfo,
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
               'any_r2cn,
               string,
               [ | `String(string) | `Int(int) | `Float(float)]
             ) =>
             'any_r8bf,
           )=?,
        ~columnEditingEnabled: option(bool)=?,
        ~columnExtensions:
           option(
             array(ColumnExtensions.t('any_r03u, 'any_ro3w, 'any_rnha)),
           )=?,
        ~editingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultEditingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onEditingRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        ~addedRows: option(array('any_r5nx))=?,
        ~defaultAddedRows: option(array('any_re8c))=?,
        ~onAddedRowsChange: option(array('any_rl68) => unit)=?,
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
        ~onCommitChanges: array(Changes.t('any_rvcb, 'a)) => unit,
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
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
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
  module Filters = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      [@bs.optional]
      value: string,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (obj |. value) {
      | Some(v) => unwrappedMap |. Js.Dict.set("value", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  module DefaultFilters = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      [@bs.optional]
      value: string,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (obj |. value) {
      | Some(v) => unwrappedMap |. Js.Dict.set("value", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      filteringEnabled: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set(
           "filteringEnabled",
           obj |. filteringEnabled |. toJsUnsafe,
         );
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~filters: array(Filters.t)=?,
      ~defaultFilters: array(DefaultFilters.t)=?,
      ~onFiltersChange: 'any_rcwc=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~columnFilteringEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "FilteringState";
  let make =
      (
        ~filters: option(array(Filters.t))=?,
        ~defaultFilters: option(array(DefaultFilters.t))=?,
        ~onFiltersChange: option(array(Filters.t) => unit)=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
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
                Js.Array.map(item => toJsUnsafe(Filters.unwrap(item)), v),
              filters,
            ),
          ~defaultFilters=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(DefaultFilters.unwrap(item)),
                  v,
                ),
              defaultFilters,
            ),
          ~onFiltersChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnFilteringEnabled?,
          (),
        ),
      children,
    );
};

module Grid = {
  module Columns = {
    [@bs.deriving abstract]
    type t('any_raq9, 'any_rutr) = {
      name: string,
      [@bs.optional]
      title: string,
      [@bs.optional]
      getCellValue: ('any_raq9, string) => 'any_rutr,
    };
    let make = t;
    let unwrap = (obj: t('any_raq9, 'any_rutr)) => {
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
      ~rows: array('any_r0rd)=?,
      ~getRowId: 'any_r402=?,
      ~getCellValue: 'any_rf0h=?,
      ~columns: array(Columns.t('any_raq9, 'any_rutr))=?,
      ~rootComponent: 'any_r70c=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_r0rd))=?,
        ~getRowId:
           option(
             'any_rgos => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_r8ml, string) => 'any_rsn3)=?,
        ~columns: option(array(Columns.t('any_raq9, 'any_rutr)))=?,
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

module GroupPanelLayout = {
  module Items = {
    [@bs.deriving abstract]
    type t('a) = {
      [@bs.optional]
      column: Js.t({..} as 'a),
      [@bs.optional]
      draft: bool,
    };
    let make = t;
    let unwrap = (obj: t('a)) => {
      let unwrappedMap = Js.Dict.empty();
      switch (obj |. column) {
      | Some(v) => unwrappedMap |. Js.Dict.set("column", v |. toJsUnsafe)
      | None => ()
      };
      switch (obj |. draft) {
      | Some(v) => unwrappedMap |. Js.Dict.set("draft", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~items: array(Items.t('a)),
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
        ~items: array(Items.t('a)),
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
          ~items=
            Js.Array.map(item => toJsUnsafe(Items.unwrap(item)), items),
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
      ~containerComponent: 'any_rhz6=?,
      ~itemComponent: 'any_rrcu=?,
      ~emptyMessageComponent: 'any_rpad=?,
      ~messages: 'any_r811=?,
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
                   "getCellValue": ('any_rt49, string) => 'any_rqx4,
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
                   "direction": [ | `Any('any_rbd3) | `Enum(direction_enum)],
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

module GroupingState = {
  module Grouping = {
    [@bs.deriving abstract]
    type t = {columnName: string};
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap;
    };
  };
  module DefaultGrouping = {
    [@bs.deriving abstract]
    type t = {columnName: string};
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap;
    };
  };
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      groupingEnabled: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("groupingEnabled", obj |. groupingEnabled |. toJsUnsafe);
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~grouping: array(Grouping.t)=?,
      ~defaultGrouping: array(DefaultGrouping.t)=?,
      ~onGroupingChange: 'any_rq9f=?,
      ~expandedGroups: 'invalidArrayType_r65d=?,
      ~defaultExpandedGroups: 'invalidArrayType_r0vg=?,
      ~onExpandedGroupsChange: 'any_retp=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~columnGroupingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "GroupingState";
  let make =
      (
        ~grouping: option(array(Grouping.t))=?,
        ~defaultGrouping: option(array(DefaultGrouping.t))=?,
        ~onGroupingChange: option(array(Grouping.t) => unit)=?,
        ~expandedGroups: option('invalidArrayType_r65d)=?,
        ~defaultExpandedGroups: option('invalidArrayType_r0vg)=?,
        ~onExpandedGroupsChange: option('invalidArrayType_rjtf => unit)=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
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
                Js.Array.map(item => toJsUnsafe(Grouping.unwrap(item)), v),
              grouping,
            ),
          ~defaultGrouping=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(DefaultGrouping.unwrap(item)),
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
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnGroupingEnabled?,
          (),
        ),
      children,
    );
};

module IntegratedFiltering = {
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t('any_rca4, 'any_rkgk) = {
      columnName: string,
      [@bs.optional]
      predicate:
        (
          'any_rca4,
          {
            .
            "columnName": string,
            "value": string,
          },
          'any_rkgk
        ) =>
        bool,
    };
    let make = t;
    let unwrap = (obj: t('any_rca4, 'any_rkgk)) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (obj |. predicate) {
      | Some(v) => unwrappedMap |. Js.Dict.set("predicate", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~columnExtensions: array(ColumnExtensions.t('any_rca4, 'any_rkgk))=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedFiltering";
  let make =
      (
        ~columnExtensions:
           option(array(ColumnExtensions.t('any_rca4, 'any_rkgk)))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
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

module IntegratedGrouping = {
  module CriteriaReturn = {
    [@bs.deriving abstract]
    type t('any_r171) = {
      key: [ | `String(string) | `Int(int) | `Float(float)],
      [@bs.optional]
      value: 'any_r171,
    };
    let make = t;
    let unwrap = (obj: t('any_r171)) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("key", unwrapValue(obj |. key) |. toJsUnsafe);
      switch (obj |. value) {
      | Some(v) => unwrappedMap |. Js.Dict.set("value", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t('any_rdmb, 'any_r171) = {
      columnName: string,
      [@bs.optional]
      criteria: 'any_rdmb => CriteriaReturn.t('any_r171),
    };
    let make = t;
    let unwrap = (obj: t('any_rdmb, 'any_r171)) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (obj |. criteria) {
      | Some(v) => unwrappedMap |. Js.Dict.set("criteria", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~columnExtensions: array(ColumnExtensions.t('any_rdmb, 'any_r171))=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedGrouping";
  let make =
      (
        ~columnExtensions:
           option(array(ColumnExtensions.t('any_rdmb, 'any_r171)))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
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
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t('any_rgq1, 'any_rky9) = {
      columnName: string,
      [@bs.optional]
      compare: ('any_rgq1, 'any_rky9) => [ | `Int(int) | `Float(float)],
    };
    let make = t;
    let unwrap = (obj: t('any_rgq1, 'any_rky9)) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (obj |. compare) {
      | Some(v) => unwrappedMap |. Js.Dict.set("compare", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~columnExtensions: array(ColumnExtensions.t('any_rgq1, 'any_rky9))=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedSorting";
  let make =
      (
        ~columnExtensions:
           option(array(ColumnExtensions.t('any_rgq1, 'any_rky9)))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
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
      ~pageSizes: 'arrayOf_ri10=?,
      ~containerComponent: 'any_r2fy=?,
      ~messages: 'any_ra3q=?,
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

module PagingState = {
  [@bs.obj]
  external makeProps :
    (
      ~pageSize: 'number_i=?,
      ~defaultPageSize: 'number_m=?,
      ~onPageSizeChange: 'any_ro22=?,
      ~currentPage: 'number_4=?,
      ~defaultCurrentPage: 'number_6=?,
      ~onCurrentPageChange: 'any_r1op=?,
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
      ~onExpandedRowIdsChange: 'any_rajb=?,
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
    (~inputComponent: 'any_r6ph=?, ~messages: 'any_rw0r=?, unit) => _ =
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

module SearchState = {
  [@bs.obj]
  external makeProps :
    (
      ~value: string=?,
      ~defaultValue: string=?,
      ~onValueChange: 'any_ru7s=?,
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
      ~onSelectionChange: 'any_rtoj=?,
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
  module Sorting = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      direction,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set(
           "direction",
           directionToJs(obj |. direction) |. toJsUnsafe,
         );
      unwrappedMap;
    };
  };
  module DefaultSorting = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      direction,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set(
           "direction",
           directionToJs(obj |. direction) |. toJsUnsafe,
         );
      unwrappedMap;
    };
  };
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      sortingEnabled: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("sortingEnabled", obj |. sortingEnabled |. toJsUnsafe);
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~sorting: array(Sorting.t)=?,
      ~defaultSorting: array(DefaultSorting.t)=?,
      ~onSortingChange: 'any_rcf1=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~columnSortingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SortingState";
  let make =
      (
        ~sorting: option(array(Sorting.t))=?,
        ~defaultSorting: option(array(DefaultSorting.t))=?,
        ~onSortingChange: option(array(Sorting.t) => unit)=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
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
                Js.Array.map(item => toJsUnsafe(Sorting.unwrap(item)), v),
              sorting,
            ),
          ~defaultSorting=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(DefaultSorting.unwrap(item)),
                  v,
                ),
              defaultSorting,
            ),
          ~onSortingChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
                  v,
                ),
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
      ~headerRows: array('any_rf09)=?,
      ~bodyRows: array('any_r8ct),
      ~columns: array('any_rl1r),
      ~minWidth: 'number_9,
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
        ~headerRows: option(array('any_rf09))=?,
        ~bodyRows: array('any_r8ct),
        ~columns: array('any_rl1r),
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
      ~columnBands: array('any_rhdx)=?,
      ~cellComponent: 'any_rgm5=?,
      ~rowComponent: 'any_roob=?,
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
        ~columnBands: option(array('any_rhdx))=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rc57,
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
                   "getCellValue": ('any_rzxb, string) => 'any_rang,
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
      ~onOrderChange: 'any_rj11=?,
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
      ~onColumnWidthsChange: 'any_rrap=?,
      ~minColumnWidth: 'number_9=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
      ~emptyMessageComponent: 'any_r3up=?,
      ~onHiddenColumnNamesChange: 'any_rko5=?,
      ~messages: 'any_r2qb=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
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
      ~cellComponent: 'any_reww=?,
      ~headerCellComponent: 'any_r7pg=?,
      ~commandComponent: 'any_ra0v=?,
      ~showAddCommand: bool=?,
      ~showEditCommand: bool=?,
      ~showDeleteCommand: bool=?,
      ~width: 'union_r49a=?,
      ~messages: 'any_runr=?,
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
                 "row": 'any_rfex,
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
                   "getCellValue": ('any_ruys, string) => 'any_rquv,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r2wp,
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
                 "row": 'any_r3w8,
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
                   "getCellValue": ('any_rje5, string) => 'any_rgae,
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
      ~rowHeight: 'number_x=?,
      ~cellComponent: 'any_rbzn=?,
      ~rowComponent: 'any_rgt8=?,
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
                 "row": 'any_rxol,
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
                   "getCellValue": ('any_res4, string) => 'any_rseq,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rxos,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r81h, string) => 'any_rd12,
               },
               "value": 'any_rjiu,
               "editingEnabled": bool,
               "onValueChange": 'any_rk2q => unit,
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
                 "row": 'any_r8dz,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_r8st,
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
      ~rowHeight: 'number_p=?,
      ~showFilterSelector: bool=?,
      ~messages: 'any_r4hd=?,
      ~cellComponent: 'any_rug7=?,
      ~rowComponent: 'any_r0f9=?,
      ~filterSelectorComponent: 'any_r8fw=?,
      ~iconComponent: 'any_r7tq=?,
      ~editorComponent: 'any_rcbv=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_rmk5,
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
                   "getCellValue": ('any_rzcf, string) => 'any_ruoe,
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
                 "getCellValue": ('any_red3, string) => 'any_rv45,
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
               "value": 'any_rllx,
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
      ~cellComponent: 'any_rpyh=?,
      ~rowComponent: 'any_rq5d=?,
      ~indentCellComponent: 'any_r58o=?,
      ~indentColumnWidth: 'number_4=?,
      ~showColumnsWhenGrouped: bool=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
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
                 "row": 'any_rq6m,
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
                   "getCellValue": ('any_rin7, string) => 'any_rvsz,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_r8kj,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rrhv, string) => 'any_rr9x,
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
                 "row": 'any_rcwe,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_renx,
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
                 "row": 'any_rtkq,
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
                   "getCellValue": ('any_rqm8, string) => 'any_rhi4,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rmjx,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rmdg, string) => 'any_r48u,
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
      ~cellComponent: 'any_rfmh=?,
      ~rowComponent: 'any_rccw=?,
      ~messages: 'any_ry4g=?,
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
                 "row": 'any_rtmg,
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
                   "getCellValue": ('any_rp24, string) => 'any_rmvh,
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
                 "getCellValue": ('any_rbvp, string) => 'any_rfs7,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_rpc2) | `Enum(direction_enum)],
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

module TableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~columns: array('any_r0x9),
      ~minColumnWidth: 'number_7,
      ~layoutComponent: 'genericCallback,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableLayout";
  let make =
      (
        ~columns: array('any_r0x9),
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
      ~contentComponent: 'any_rq01=?,
      ~toggleCellComponent: 'any_rire=?,
      ~cellComponent: 'any_rb3p=?,
      ~rowComponent: 'any_r6qw=?,
      ~toggleColumnWidth: 'number_c=?,
      ~rowHeight: 'number_e=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_rju8} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r8ub,
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
                   "getCellValue": ('any_run3, string) => 'any_rxh7,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rhto,
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
                 "row": 'any_rd21,
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
                   "getCellValue": ('any_rqu1, string) => 'any_rwgg,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r26j,
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
                 "row": 'any_rkah,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rbql,
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
      ~headerCellComponent: 'any_ry78=?,
      ~cellComponent: 'any_ryju=?,
      ~rowComponent: 'genericCallback=?,
      ~highlightRow: bool=?,
      ~selectByRowClick: bool=?,
      ~showSelectAll: bool=?,
      ~showSelectionColumn: bool=?,
      ~selectionColumnWidth: 'number_g=?,
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
                 "row": 'any_rou9,
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
                   "getCellValue": ('any_rq8k, string) => 'any_r73j,
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
                 "row": 'any_r4e3,
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
                   "getCellValue": ('any_rspw, string) => 'any_rkvt,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_ryr4,
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
      ~cellComponent: 'any_ru1m=?,
      ~indentComponent: 'any_rpxr=?,
      ~expandButtonComponent: 'any_rogl=?,
      ~checkboxComponent: 'any_rf25=?,
      ~contentComponent: 'any_rly3=?,
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
                 "row": 'any_rk6j,
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
                   "getCellValue": ('any_rb23, string) => 'any_rynz,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_r48a,
               "row": 'any_rg3h,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rh6v, string) => 'any_rc4g,
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
      ~cellComponent: 'any_rxgl=?,
      ~rowComponent: 'any_r8fx=?,
      ~noDataCellComponent: 'any_rwg5=?,
      ~noDataRowComponent: 'any_rvib=?,
      ~stubRowComponent: 'any_r7l9=?,
      ~stubCellComponent: 'any_rzzj=?,
      ~stubHeaderCellComponent: 'any_r4kj=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~messages: 'any_r2uw=?,
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
                 "row": 'any_rbar,
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
                   "getCellValue": ('any_rcwi, string) => 'any_rcqv,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rse9,
               "row": 'any_roq6,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r7v4, string) => 'any_rx09,
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
                 "row": 'any_rjjr,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rvvu,
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
                 "row": 'any_rbtv,
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
                   "getCellValue": ('any_r9n9, string) => 'any_r8bn,
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
                 "row": 'any_r1ff,
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
                 "row": 'any_rsoy,
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
                 "row": 'any_r8cv,
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
                   "getCellValue": ('any_re1g, string) => 'any_r1uw,
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
                 "row": 'any_roqs,
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
                   "getCellValue": ('any_rcni, string) => 'any_r4mf,
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
      ~rootComponent: 'any_r00p=?,
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
      ~onExpandedRowIdsChange: 'any_rruk=?,
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
      ~minWidth: 'number_l,
      ~minColumnWidth: 'number_j,
      ~height: 'number_t,
      ~headerRows: array('any_r8iw)=?,
      ~bodyRows: array('any_rg3g),
      ~columns: array('any_rfqq),
      ~cellComponent: 'genericCallback,
      ~rowComponent: 'genericCallback,
      ~bodyComponent: 'genericCallback,
      ~headComponent: 'genericCallback=?,
      ~tableComponent: 'genericCallback,
      ~headTableComponent: 'genericCallback=?,
      ~containerComponent: 'genericCallback,
      ~estimatedRowHeight: 'number_z,
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
        ~headerRows: option(array('any_r8iw))=?,
        ~bodyRows: array('any_rg3g),
        ~columns: array('any_rfqq),
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
