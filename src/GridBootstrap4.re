
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
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                showColumnChooser: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> showColumnChooserGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "showColumnChooser",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~overlayComponent: 'any_r4ja=?,
~containerComponent: 'any_rcpz=?,
~itemComponent: 'any_rggf=?,
~toggleButtonComponent: 'any_r2jj=?,
~messages: 'any_rjs7=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "ColumnChooser";
                let make = (
                    ~overlayComponent: option(({.
                    "visible": bool,"target": 'any_rsbg,"onHide": unit => unit,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~containerComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~itemComponent: option(({.
                    "item": {.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_rsyo, string) => 'any_r8hh
                },"hidden": bool
                },"disabled": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~toggleButtonComponent: option(({.
                    "onToggle": unit => unit,"getMessage": (string) => string,"buttonRef": ('any_ra3c) => unit
                }) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~overlayComponent=?overlayComponent,
~containerComponent=?containerComponent,
~itemComponent=?itemComponent,
~toggleButtonComponent=?toggleButtonComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module DragDropProvider = {
                
                [@bs.obj] external makeProps : (~containerComponent: 'any_r51o=?,
~columnComponent: 'any_rc7y=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "DragDropProvider";
                let make = (
                    ~containerComponent: option(({.
                    "clientOffset": {.
                    "x": [ | `Int(int) | `Float(float) ],"y": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~columnComponent: option(({.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_rgvr, string) => 'any_rbcd
                }
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~containerComponent=?containerComponent,
~columnComponent=?columnComponent, ()),
                        children
                    );
            };
        

            module Grid = {
                

                    module Columns {
                        [@bs.deriving abstract]
                        type t('any_rooo,'any_r5wb) = {
                            
                                
                                
                                name: string
                            ,
                                [@bs.optional]
                                
                                title: string
                            ,
                                [@bs.optional]
                                
                                getCellValue: ('any_rooo, string) => 'any_r5wb
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_rooo,'any_r5wb)) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "name",
                                            obj -> nameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> titleGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "title",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (obj -> getCellValueGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "getCellValue",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~rows: array('any_re2u)=?,
~getRowId: 'any_r56e=?,
~getCellValue: 'any_rwz2=?,
~columns: array(Columns.t('any_rooo,'any_r5wb))=?,
~rootComponent: 'any_rkwf=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "Grid";
                let make = (
                    ~rows: option(array('any_re2u))=?,
~getRowId: option(('any_rlab) => [ | `Int(int) | `Float(float) | `String(string)  ])=?,
~getCellValue: option(('any_rz9e, string) => 'any_rqli)=?,
~columns: option(array(Columns.t('any_rooo,'any_r5wb)))=?,
~rootComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~rows=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), rows),
~getRowId=?getRowId,
~getCellValue=?getCellValue,
~columns=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(Columns.unwrap(item)), v)), columns),
~rootComponent=?rootComponent, ()),
                        children
                    );
            };
        

            module GroupingPanel = {
                

                [@bs.deriving jsConverter]
                type sortingDirection = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                [@bs.deriving jsConverter]
                type direction_enum = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                groupByColumn: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> groupByColumnGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "groupByColumn",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~showSortingControls: bool=?,
~showGroupingControls: bool=?,
~layoutComponent: 'genericCallback=?,
~containerComponent: 'any_rbhx=?,
~itemComponent: 'any_rtmg=?,
~emptyMessageComponent: 'any_rxid=?,
~messages: 'any_r5hl=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "GroupingPanel";
                let make = (
                    ~showSortingControls: option(bool)=?,
~showGroupingControls: option(bool)=?,
~layoutComponent: option('genericCallback)=?,
~containerComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~itemComponent: option(({.
                    "item": {.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_r5oh, string) => 'any_rpfh
                },"draft": string
                },"showGroupingControls": bool,"showSortingControls": bool,"groupingEnabled": bool,"sortingEnabled": bool,"sortingDirection": sortingDirection,"onSort": ({.
                    "direction": [ | `Any('any_ry7i) | `Enum(direction_enum)  ]
                }) => unit,"onGroup": unit => unit
                }) => ReasonReact.reactElement)=?,
~emptyMessageComponent: option(({.
                    "getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~showSortingControls=?showSortingControls,
~showGroupingControls=?showGroupingControls,
~layoutComponent=?layoutComponent,
~containerComponent=?containerComponent,
~itemComponent=?itemComponent,
~emptyMessageComponent=?emptyMessageComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module PagingPanel = {
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                showAll: string
                            ,
                                [@bs.optional]
                                
                                rowsPerPage: string
                            ,
                                [@bs.optional]
                                
                                info: ({.
                    "from": [ | `Int(int) | `Float(float) ],"to": [ | `Int(int) | `Float(float) ],"count": [ | `Int(int) | `Float(float) ]
                }) => [ | `String(string) | `String(string)  ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> showAllGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "showAll",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> rowsPerPageGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "rowsPerPage",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> infoGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "info",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~pageSizes: 'arrayOf_r4yn=?,
~containerComponent: 'any_rij2=?,
~messages: 'any_rb1h=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "PagingPanel";
                let make = (
                    ~pageSizes: option([ | `IntArray(array(int))| `FloatArray(array(float)) ])=?,
~containerComponent: option(({.
                    "totalPages": [ | `Int(int) | `Float(float) ],"currentPage": [ | `Int(int) | `Float(float) ],"onCurrentPageChange": ([ | `Int(int) | `Float(float) ]) => unit,"pageSize": [ | `Int(int) | `Float(float) ],"onPageSizeChange": ([ | `Int(int) | `Float(float) ]) => unit,"pageSizes": [ | `IntArray(array(int))| `FloatArray(array(float)) ],"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~pageSizes=?Js.Option.map([@bs] ((v) => unwrapValue(v)), pageSizes),
~containerComponent=?containerComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module SearchPanel = {
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                searchPlaceholder: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> searchPlaceholderGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "searchPlaceholder",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~inputComponent: 'any_rpn6=?,
~messages: 'any_rdgw=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "SearchPanel";
                let make = (
                    ~inputComponent: option(({.
                    "value": string,"onValueChange": (string) => unit,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~inputComponent=?inputComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module TableBandHeader = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~columnBands: array('any_rf1x)=?,
~cellComponent: 'any_rfd8=?,
~rowComponent: 'any_r765=?,
~bandedHeaderCellComponent: 'genericCallback=?,
~invisibleCellComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableBandHeader";
                let make = (
                    ~columnBands: option(array('any_rf1x))=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ra3p,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rd8k, string) => 'any_rklk
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~bandedHeaderCellComponent: option('genericCallback)=?,
~invisibleCellComponent: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~columnBands=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), columnBands),
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~bandedHeaderCellComponent=?bandedHeaderCellComponent,
~invisibleCellComponent=?invisibleCellComponent, ()),
                        children
                    );
            };
        

            module TableColumnReordering = {
                
                [@bs.obj] external makeProps : (~order: array(string)=?,
~defaultOrder: array(string)=?,
~onOrderChange: 'any_rqcb=?,
~tableContainerComponent: 'genericCallback=?,
~rowComponent: 'genericCallback=?,
~cellComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableColumnReordering";
                let make = (
                    ~order: option(array(string))=?,
~defaultOrder: option(array(string))=?,
~onOrderChange: option((array(string)) => unit)=?,
~tableContainerComponent: option('genericCallback)=?,
~rowComponent: option('genericCallback)=?,
~cellComponent: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~order=?order,
~defaultOrder=?defaultOrder,
~onOrderChange=?onOrderChange,
~tableContainerComponent=?tableContainerComponent,
~rowComponent=?rowComponent,
~cellComponent=?cellComponent, ()),
                        children
                    );
            };
        

            module TableColumnResizing = {
                

                    module DefaultColumnWidths {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                width: [ | `Int(int) | `Float(float) ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "width",
                                            unwrapValue(obj -> widthGet)
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module ColumnWidths {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                width: [ | `Int(int) | `Float(float) ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "width",
                                            unwrapValue(obj -> widthGet)
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module NextColumnWidths {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                width: [ | `Int(int) | `Float(float) ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "width",
                                            unwrapValue(obj -> widthGet)
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~defaultColumnWidths: array(DefaultColumnWidths.t)=?,
~columnWidths: array(ColumnWidths.t)=?,
~onColumnWidthsChange: 'any_r62z=?,
~minColumnWidth: 'number_y=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableColumnResizing";
                let make = (
                    ~defaultColumnWidths: option(array(DefaultColumnWidths.t))=?,
~columnWidths: option(array(ColumnWidths.t))=?,
~onColumnWidthsChange: option((array(NextColumnWidths.t)) => unit)=?,
~minColumnWidth: option([ | `Int(int) | `Float(float) ])=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~defaultColumnWidths=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(DefaultColumnWidths.unwrap(item)), v)), defaultColumnWidths),
~columnWidths=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnWidths.unwrap(item)), v)), columnWidths),
~onColumnWidthsChange=?onColumnWidthsChange,
~minColumnWidth=?Js.Option.map([@bs] ((v) => unwrapValue(v)), minColumnWidth), ()),
                        children
                    );
            };
        

            module TableColumnVisibility = {
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                noColumns: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> noColumnsGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "noColumns",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                togglingEnabled: bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "togglingEnabled",
                                            obj -> togglingEnabledGet
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~hiddenColumnNames: array(string)=?,
~defaultHiddenColumnNames: array(string)=?,
~emptyMessageComponent: 'any_rchg=?,
~onHiddenColumnNamesChange: 'any_rxhf=?,
~messages: 'any_rd60=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~columnTogglingEnabled: bool=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableColumnVisibility";
                let make = (
                    ~hiddenColumnNames: option(array(string))=?,
~defaultHiddenColumnNames: option(array(string))=?,
~emptyMessageComponent: option(({.
                    "getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~onHiddenColumnNamesChange: option((array(string)) => unit)=?,
~messages: option(Messages.t)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
~columnTogglingEnabled: option(bool)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~hiddenColumnNames=?hiddenColumnNames,
~defaultHiddenColumnNames=?defaultHiddenColumnNames,
~emptyMessageComponent=?emptyMessageComponent,
~onHiddenColumnNamesChange=?onHiddenColumnNamesChange,
~messages=?Messages.unwrap(messages),
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions),
~columnTogglingEnabled=?columnTogglingEnabled, ()),
                        children
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

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                addCommand: string
                            ,
                                [@bs.optional]
                                
                                editCommand: string
                            ,
                                [@bs.optional]
                                
                                deleteCommand: string
                            ,
                                [@bs.optional]
                                
                                commitCommand: string
                            ,
                                [@bs.optional]
                                
                                cancelCommand: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> addCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "addCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> editCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "editCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> deleteCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "deleteCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> commitCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "commitCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> cancelCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "cancelCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~cellComponent: 'any_rqn9=?,
~headerCellComponent: 'any_r3bm=?,
~commandComponent: 'any_raml=?,
~showAddCommand: bool=?,
~showEditCommand: bool=?,
~showDeleteCommand: bool=?,
~width: 'union_r3gk=?,
~messages: 'any_reqd=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableEditColumn";
                let make = (
                    ~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rao3,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rw5d, string) => 'any_rzc4
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_rzsh,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~headerCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_raor,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r1vi, string) => 'any_ryof
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~commandComponent: option(({.
                    "id": id,"text": string,"onExecute": unit => unit
                }) => ReasonReact.reactElement)=?,
~showAddCommand: option(bool)=?,
~showEditCommand: option(bool)=?,
~showDeleteCommand: option(bool)=?,
~width: option([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~cellComponent=?cellComponent,
~headerCellComponent=?headerCellComponent,
~commandComponent=?commandComponent,
~showAddCommand=?showAddCommand,
~showEditCommand=?showEditCommand,
~showDeleteCommand=?showDeleteCommand,
~width=?Js.Option.map([@bs] (v => unwrapValue(v)), width),
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module TableEditRow = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~rowHeight: 'number_k=?,
~cellComponent: 'any_r03k=?,
~rowComponent: 'any_r1ol=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableEditRow";
                let make = (
                    ~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rr6v,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r0dr, string) => 'any_ra61
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r41u,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rrdc, string) => 'any_rpcw
                },"value": 'any_rcmk,"editingEnabled": bool,"onValueChange": ('any_r3ji) => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r7rp,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_rho2
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~rowHeight=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowHeight),
~cellComponent=?cellComponent,
~rowComponent=?rowComponent, ()),
                        children
                    );
            };
        

            module TableFilterRow = {
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                filterPlaceholder: string
                            ,
                                [@bs.optional]
                                
                                contains: string
                            ,
                                [@bs.optional]
                                
                                notContains: string
                            ,
                                [@bs.optional]
                                
                                startsWith: string
                            ,
                                [@bs.optional]
                                
                                endsWith: string
                            ,
                                [@bs.optional]
                                
                                equal: string
                            ,
                                [@bs.optional]
                                
                                notEqual: string
                            ,
                                [@bs.optional]
                                
                                greaterThan: string
                            ,
                                [@bs.optional]
                                
                                greaterThanOrEqual: string
                            ,
                                [@bs.optional]
                                
                                lessThan: string
                            ,
                                [@bs.optional]
                                
                                lessThanOrEqual: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> filterPlaceholderGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "filterPlaceholder",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> containsGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "contains",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> notContainsGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "notContains",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> startsWithGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "startsWith",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> endsWithGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "endsWith",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> equalGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "equal",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> notEqualGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "notEqual",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> greaterThanGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "greaterThan",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> greaterThanOrEqualGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "greaterThanOrEqual",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> lessThanGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "lessThan",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> lessThanOrEqualGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "lessThanOrEqual",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~rowHeight: 'number_4=?,
~showFilterSelector: bool=?,
~messages: 'any_r18g=?,
~cellComponent: 'any_r6hg=?,
~rowComponent: 'any_r0pp=?,
~filterSelectorComponent: 'any_r9fm=?,
~iconComponent: 'any_rn3z=?,
~editorComponent: 'any_rk07=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableFilterRow";
                let make = (
                    ~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
~showFilterSelector: option(bool)=?,
~messages: option(Messages.t)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rkwt,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r0as, string) => 'any_ro3r
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"filter": {.
                    "columnName": string,"operation": Js.t({..}),"value": string
                },"onFilter": ({.
                    "columnName": string,"operation": Js.t({..}),"value": string
                }) => unit,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r80c, string) => 'any_r9c5
                },"filteringEnabled": bool,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~rowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~filterSelectorComponent: option(({.
                    "iconComponent": ({.
                    "type": string
                }) => ReasonReact.reactElement,"value": string,"availableValues": array(string),"onChange": (string) => unit,"disabled": bool,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~iconComponent: option(({.
                    "type": string
                }) => ReasonReact.reactElement)=?,
~editorComponent: option(({.
                    "value": 'any_rntd,"disabled": bool,"onChange": (string) => unit,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~rowHeight=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowHeight),
~showFilterSelector=?showFilterSelector,
~messages=?Messages.unwrap(messages),
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~filterSelectorComponent=?filterSelectorComponent,
~iconComponent=?iconComponent,
~editorComponent=?editorComponent, ()),
                        children
                    );
            };
        

            module TableGroupRow = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                showWhenGrouped: bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> showWhenGroupedGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "showWhenGrouped",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~cellComponent: 'any_r4rg=?,
~rowComponent: 'any_rico=?,
~indentCellComponent: 'any_rowq=?,
~indentColumnWidth: 'number_v=?,
~showColumnsWhenGrouped: bool=?,
~columnExtensions: array(ColumnExtensions.t)=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableGroupRow";
                let make = (
                    ~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ryib,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r2k5, string) => 'any_rfu8
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_rpja
                },"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rion, string) => 'any_rjl3
                },"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r4oc,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_r1w5
                }
                }) => ReasonReact.reactElement)=?,
~indentCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rryr,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rsmj, string) => 'any_rtuh
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_ry8a
                },"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rndl, string) => 'any_raub
                }
                }) => ReasonReact.reactElement)=?,
~indentColumnWidth: option([ | `Int(int) | `Float(float) ])=?,
~showColumnsWhenGrouped: option(bool)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~indentCellComponent=?indentCellComponent,
~indentColumnWidth=?Js.Option.map([@bs] ((v) => unwrapValue(v)), indentColumnWidth),
~showColumnsWhenGrouped=?showColumnsWhenGrouped,
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions), ()),
                        children
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
                type sortingDirection = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                [@bs.deriving jsConverter]
                type direction_enum = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                sortingHint: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> sortingHintGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "sortingHint",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~showSortingControls: bool=?,
~showGroupingControls: bool=?,
~cellComponent: 'any_rx34=?,
~rowComponent: 'any_rmu3=?,
~messages: 'any_rl2x=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableHeaderRow";
                let make = (
                    ~showSortingControls: option(bool)=?,
~showGroupingControls: option(bool)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ripx,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rfpe, string) => 'any_rvgt
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rgyp, string) => 'any_ror8
                },"showSortingControls": bool,"sortingEnabled": bool,"sortingDirection": sortingDirection,"onSort": ({.
                    "direction": [ | `Any('any_rpe7) | `Enum(direction_enum)  ],"keepOther": bool
                }) => unit,"showGroupingControls": bool,"groupingEnabled": bool,"onGroup": unit => unit,"resizingEnabled": bool,"onWidthChange": ({.
                    "shift": [ | `Int(int) | `Float(float) ]
                }) => unit,"onWidthDraft": ({.
                    "shift": [ | `Int(int) | `Float(float) ]
                }) => unit,"onWidthDraftCancel": unit => unit,"draggingEnabled": bool,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~rowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~showSortingControls=?showSortingControls,
~showGroupingControls=?showGroupingControls,
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module TableRowDetail = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~contentComponent: 'any_rl7a=?,
~toggleCellComponent: 'any_rrxe=?,
~cellComponent: 'any_rtdh=?,
~rowComponent: 'any_re2n=?,
~toggleColumnWidth: 'number_z=?,
~rowHeight: 'number_n=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableRowDetail";
                let make = (
                    ~contentComponent: option(({.
                    "row": 'any_rerh
                }) => ReasonReact.reactElement)=?,
~toggleCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rial,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rlef, string) => 'any_r47q
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r4rr,"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rrgs,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rlx5, string) => 'any_rcq5
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_rxg6,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_riv4,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_r8mz
                }) => ReasonReact.reactElement)=?,
~toggleColumnWidth: option([ | `Int(int) | `Float(float) ])=?,
~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~contentComponent=?contentComponent,
~toggleCellComponent=?toggleCellComponent,
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~toggleColumnWidth=?Js.Option.map([@bs] ((v) => unwrapValue(v)), toggleColumnWidth),
~rowHeight=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowHeight), ()),
                        children
                    );
            };
        

            module TableSelection = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~headerCellComponent: 'any_r4pa=?,
~cellComponent: 'any_r6qs=?,
~rowComponent: 'genericCallback=?,
~highlightRow: bool=?,
~selectByRowClick: bool=?,
~showSelectAll: bool=?,
~showSelectionColumn: bool=?,
~selectionColumnWidth: 'number_n=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableSelection";
                let make = (
                    ~headerCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rmuz,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r9gy, string) => 'any_rikv
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"disabled": bool,"allSelected": bool,"someSelected": bool,"onToggle": (bool) => unit
                }) => ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r5qj,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rvv6, string) => 'any_r7ey
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r7o4,"selected": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option('genericCallback)=?,
~highlightRow: option(bool)=?,
~selectByRowClick: option(bool)=?,
~showSelectAll: option(bool)=?,
~showSelectionColumn: option(bool)=?,
~selectionColumnWidth: option([ | `Int(int) | `Float(float) ])=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~headerCellComponent=?headerCellComponent,
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~highlightRow=?highlightRow,
~selectByRowClick=?selectByRowClick,
~showSelectAll=?showSelectAll,
~showSelectionColumn=?showSelectionColumn,
~selectionColumnWidth=?Js.Option.map([@bs] ((v) => unwrapValue(v)), selectionColumnWidth), ()),
                        children
                    );
            };
        

            module TableSummaryRow = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                count: string
                            ,
                                [@bs.optional]
                                
                                sum: string
                            ,
                                [@bs.optional]
                                
                                min: string
                            ,
                                [@bs.optional]
                                
                                max: string
                            ,
                                [@bs.optional]
                                
                                avg: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> countGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "count",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> sumGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "sum",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> minGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "min",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> maxGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "max",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> avgGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "avg",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~formatlessSummaryTypes: array(string)=?,
~totalRowComponent: 'any_ruur=?,
~groupRowComponent: 'any_r74a=?,
~treeRowComponent: 'any_roqi=?,
~totalCellComponent: 'any_r9kp=?,
~groupCellComponent: 'any_rctt=?,
~treeCellComponent: 'any_rvcv=?,
~treeColumnCellComponent: 'any_riqo=?,
~treeColumnContentComponent: 'any_r2gm=?,
~treeColumnIndentComponent: 'any_rubp=?,
~itemComponent: ReasonReact.reactElement=?,
~messages: 'any_rwdm=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableSummaryRow";
                let make = (
                    ~formatlessSummaryTypes: option(array(string))=?,
~totalRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~groupRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~treeRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~totalCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rahv,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rq6l, string) => 'any_rw31
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r3qs, string) => 'any_rfjg
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~groupCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r8hu,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rrmc, string) => 'any_ruzd
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rxhc, string) => 'any_rjg7
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rtah,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_ru1j, string) => 'any_rkx1
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r56s, string) => 'any_r0nz
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeColumnCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rrbc,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rflg, string) => 'any_rqwa
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_re2q, string) => 'any_r3vb
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeColumnContentComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeColumnIndentComponent: option(({.
                    "level": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~itemComponent: option(ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~formatlessSummaryTypes=?formatlessSummaryTypes,
~totalRowComponent=?totalRowComponent,
~groupRowComponent=?groupRowComponent,
~treeRowComponent=?treeRowComponent,
~totalCellComponent=?totalCellComponent,
~groupCellComponent=?groupCellComponent,
~treeCellComponent=?treeCellComponent,
~treeColumnCellComponent=?treeColumnCellComponent,
~treeColumnContentComponent=?treeColumnContentComponent,
~treeColumnIndentComponent=?treeColumnIndentComponent,
~itemComponent=?itemComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module TableTreeColumn = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~_for: string=?,
~showSelectionControls: bool=?,
~showSelectAll: bool=?,
~cellComponent: 'any_rm9s=?,
~indentComponent: 'any_rib3=?,
~expandButtonComponent: 'any_rppz=?,
~checkboxComponent: 'any_rlv1=?,
~contentComponent: 'any_rfm5=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "TableTreeColumn";
                let make = (
                    ~for_: option(string)=?,
~showSelectionControls: option(bool)=?,
~showSelectAll: option(bool)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r6sc,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rvun, string) => 'any_rkx4
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"value": 'any_r3sc,"row": 'any_rbpt,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_ratp, string) => 'any_rmo4
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~indentComponent: option(({.
                    "level": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~expandButtonComponent: option(({.
                    "visible": bool,"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~checkboxComponent: option(({.
                    "disabled": bool,"checked": bool,"indeterminate": bool,"onChange": unit => unit
                }) => ReasonReact.reactElement)=?,
~contentComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~_for=?for_,
~showSelectionControls=?showSelectionControls,
~showSelectAll=?showSelectAll,
~cellComponent=?cellComponent,
~indentComponent=?indentComponent,
~expandButtonComponent=?expandButtonComponent,
~checkboxComponent=?checkboxComponent,
~contentComponent=?contentComponent, ()),
                        children
                    );
            };
        

            module Table = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                width: [ | `Int(int) | `Float(float) ]
                            ,
                                [@bs.optional]
                                
                                align: align
                            ,
                                [@bs.optional]
                                
                                wordWrapEnabled: bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (Js.Option.map([@bs] ((v) => unwrapValue(v)), obj -> widthGet)) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "width",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (Js.Option.map([@bs] (v => alignToJs(v)), obj -> alignGet)) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "align",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (obj -> wordWrapEnabledGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "wordWrapEnabled",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                noData: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> noDataGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "noData",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~layoutComponent: 'genericCallback=?,
~tableComponent: ReasonReact.reactElement=?,
~headComponent: ReasonReact.reactElement=?,
~bodyComponent: ReasonReact.reactElement=?,
~footerComponent: ReasonReact.reactElement=?,
~containerComponent: ReasonReact.reactElement=?,
~cellComponent: 'any_r5ho=?,
~rowComponent: 'any_r7gq=?,
~noDataCellComponent: 'any_rik2=?,
~noDataRowComponent: 'any_renq=?,
~stubRowComponent: 'any_ryum=?,
~stubCellComponent: 'any_rnn9=?,
~stubHeaderCellComponent: 'any_r4pq=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~messages: 'any_r7mu=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "Table";
                let make = (
                    ~layoutComponent: option('genericCallback)=?,
~tableComponent: option(ReasonReact.reactElement)=?,
~headComponent: option(ReasonReact.reactElement)=?,
~bodyComponent: option(ReasonReact.reactElement)=?,
~footerComponent: option(ReasonReact.reactElement)=?,
~containerComponent: option(ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r8rs,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rt2y, string) => 'any_rtqx
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"value": 'any_r1w7,"row": 'any_ry89,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rz3f, string) => 'any_rntw
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rtek,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_rphn
                }) => ReasonReact.reactElement)=?,
~noDataCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r1q1,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rq9w, string) => 'any_rbm7
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~noDataRowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rhld,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~stubRowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rot4,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~stubCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rhk6,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r4ig, string) => 'any_rt9n
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~stubHeaderCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rnae,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rztu, string) => 'any_rj3n
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~layoutComponent=?layoutComponent,
~tableComponent=?tableComponent,
~headComponent=?headComponent,
~bodyComponent=?bodyComponent,
~footerComponent=?footerComponent,
~containerComponent=?containerComponent,
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~noDataCellComponent=?noDataCellComponent,
~noDataRowComponent=?noDataRowComponent,
~stubRowComponent=?stubRowComponent,
~stubCellComponent=?stubCellComponent,
~stubHeaderCellComponent=?stubHeaderCellComponent,
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions),
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module Toolbar = {
                
                [@bs.obj] external makeProps : (~rootComponent: 'any_r6i5=?,
~flexibleSpaceComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "Toolbar";
                let make = (
                    ~rootComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~flexibleSpaceComponent: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~rootComponent=?rootComponent,
~flexibleSpaceComponent=?flexibleSpaceComponent, ()),
                        children
                    );
            };
        

            module VirtualTable = {
                

                [@bs.deriving jsConverter]
                type height_enum = [
                    | [@bs.as "auto"] `Auto
                ];

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                noData: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> noDataGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "noData",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~estimatedRowHeight: 'number_x=?,
~height: 'union_rrha=?,
~headTableComponent: 'genericCallback=?,
~footerTableComponent: 'genericCallback=?,
~messages: 'any_r7do=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap4"] external reactClass : ReasonReact.reactClass = "VirtualTable";
                let make = (
                    ~estimatedRowHeight: option([ | `Int(int) | `Float(float) ])=?,
~height: option([ | `Int(int) | `Float(float) | `Enum(height_enum)  ])=?,
~headTableComponent: option('genericCallback)=?,
~footerTableComponent: option('genericCallback)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~estimatedRowHeight=?Js.Option.map([@bs] ((v) => unwrapValue(v)), estimatedRowHeight),
~height=?
                    Js.Option.map([@bs] ((v) => switch v {
                        | `Enum(v) => unwrapValue(`String(height_enumToJs(v)))
                        
                        | v => unwrapValue(v)
                    }), height)
                ,
~headTableComponent=?headTableComponent,
~footerTableComponent=?footerTableComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        