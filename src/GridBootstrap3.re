
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
                
                [@bs.obj] external makeProps : (~overlayComponent: 'any_r3e2=?,
~containerComponent: 'any_r8xp=?,
~itemComponent: 'any_r2t5=?,
~toggleButtonComponent: 'any_r7ws=?,
~messages: 'any_rwwk=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "ColumnChooser";
                let make = (
                    ~overlayComponent: option(({.
                    "visible": bool,"target": 'any_r98v,"onHide": unit => unit,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~containerComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~itemComponent: option(({.
                    "item": {.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_ra5n, string) => 'any_rxv2
                },"hidden": bool
                },"disabled": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~toggleButtonComponent: option(({.
                    "onToggle": unit => unit,"getMessage": (string) => string,"buttonRef": ('any_ra8i) => unit
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
                
                [@bs.obj] external makeProps : (~containerComponent: 'any_rccv=?,
~columnComponent: 'any_r4vs=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "DragDropProvider";
                let make = (
                    ~containerComponent: option(({.
                    "clientOffset": {.
                    "x": [ | `Int(int) | `Float(float) ],"y": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~columnComponent: option(({.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_r9vr, string) => 'any_r5g5
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
                        type t('any_ruhf,'any_r02f) = {
                            
                                
                                
                                name: string
                            ,
                                [@bs.optional]
                                
                                title: string
                            ,
                                [@bs.optional]
                                
                                getCellValue: ('any_ruhf, string) => 'any_r02f
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_ruhf,'any_r02f)) => {
                            
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
                
                [@bs.obj] external makeProps : (~rows: array('any_rkv5)=?,
~getRowId: 'any_rmwk=?,
~getCellValue: 'any_rakq=?,
~columns: array(Columns.t('any_ruhf,'any_r02f))=?,
~rootComponent: 'any_rhle=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "Grid";
                let make = (
                    ~rows: option(array('any_rkv5))=?,
~getRowId: option(('any_resd) => [ | `Int(int) | `Float(float) | `String(string)  ])=?,
~getCellValue: option(('any_r5yb, string) => 'any_rpc6)=?,
~columns: option(array(Columns.t('any_ruhf,'any_r02f)))=?,
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
~containerComponent: 'any_re1e=?,
~itemComponent: 'any_rsd5=?,
~emptyMessageComponent: 'any_rbxy=?,
~messages: 'any_r3gs=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "GroupingPanel";
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
                    "name": string,"title": string,"getCellValue": ('any_rfr5, string) => 'any_rtt2
                },"draft": string
                },"showGroupingControls": bool,"showSortingControls": bool,"groupingEnabled": bool,"sortingEnabled": bool,"sortingDirection": sortingDirection,"onSort": ({.
                    "direction": [ | `Any('any_rar6) | `Enum(direction_enum)  ]
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
                
                [@bs.obj] external makeProps : (~pageSizes: 'arrayOf_rar7=?,
~containerComponent: 'any_r2hh=?,
~messages: 'any_r0cv=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "PagingPanel";
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
                
                [@bs.obj] external makeProps : (~inputComponent: 'any_rfy5=?,
~messages: 'any_rkvx=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "SearchPanel";
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
                [@bs.obj] external makeProps : (~columnBands: array('any_r247)=?,
~cellComponent: 'any_rp1z=?,
~rowComponent: 'any_rj90=?,
~bandedHeaderCellComponent: 'genericCallback=?,
~invisibleCellComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableBandHeader";
                let make = (
                    ~columnBands: option(array('any_r247))=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r2yn,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rl80, string) => 'any_rlc0
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
~onOrderChange: 'any_r023=?,
~tableContainerComponent: 'genericCallback=?,
~rowComponent: 'genericCallback=?,
~cellComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableColumnReordering";
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
~onColumnWidthsChange: 'any_r25q=?,
~minColumnWidth: 'number_z=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableColumnResizing";
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
~emptyMessageComponent: 'any_r02m=?,
~onHiddenColumnNamesChange: 'any_r830=?,
~messages: 'any_rhkc=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~columnTogglingEnabled: bool=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableColumnVisibility";
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
                
                [@bs.obj] external makeProps : (~cellComponent: 'any_rzd2=?,
~headerCellComponent: 'any_ruk8=?,
~commandComponent: 'any_rll0=?,
~showAddCommand: bool=?,
~showEditCommand: bool=?,
~showDeleteCommand: bool=?,
~width: 'union_rb81=?,
~messages: 'any_rt22=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableEditColumn";
                let make = (
                    ~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rp8z,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rasv, string) => 'any_rn52
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_ryru,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~headerCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rkj5,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rxmr, string) => 'any_re7t
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
                [@bs.obj] external makeProps : (~rowHeight: 'number_w=?,
~cellComponent: 'any_rvuh=?,
~rowComponent: 'any_r509=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableEditRow";
                let make = (
                    ~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rlrh,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r0mg, string) => 'any_rgec
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_ru55,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r0w5, string) => 'any_rowi
                },"value": 'any_ro5i,"editingEnabled": bool,"onValueChange": ('any_rtly) => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rwte,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_rhjd
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
                [@bs.obj] external makeProps : (~rowHeight: 'number_k=?,
~showFilterSelector: bool=?,
~messages: 'any_ryxw=?,
~cellComponent: 'any_r6r6=?,
~rowComponent: 'any_rn82=?,
~filterSelectorComponent: 'any_rbsq=?,
~iconComponent: 'any_rg2l=?,
~editorComponent: 'any_r4ce=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableFilterRow";
                let make = (
                    ~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
~showFilterSelector: option(bool)=?,
~messages: option(Messages.t)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r0ao,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rifi, string) => 'any_rlr9
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"filter": {.
                    "columnName": string,"operation": Js.t({..}),"value": string
                },"onFilter": ({.
                    "columnName": string,"operation": Js.t({..}),"value": string
                }) => unit,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r7tp, string) => 'any_r2bv
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
                    "value": 'any_rc3u,"disabled": bool,"onChange": (string) => unit,"getMessage": (string) => string
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
                
                [@bs.obj] external makeProps : (~cellComponent: 'any_rpfl=?,
~rowComponent: 'any_r735=?,
~indentCellComponent: 'any_rqes=?,
~indentColumnWidth: 'number_s=?,
~showColumnsWhenGrouped: bool=?,
~columnExtensions: array(ColumnExtensions.t)=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableGroupRow";
                let make = (
                    ~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rxbd,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rjpe, string) => 'any_rk60
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_r4ut
                },"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rwre, string) => 'any_rjhs
                },"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rnxg,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_r0jb
                }
                }) => ReasonReact.reactElement)=?,
~indentCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_resz,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rtwy, string) => 'any_rv6m
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_rui3
                },"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rebi, string) => 'any_rki2
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
~cellComponent: 'any_rarg=?,
~rowComponent: 'any_rokh=?,
~messages: 'any_r95o=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableHeaderRow";
                let make = (
                    ~showSortingControls: option(bool)=?,
~showGroupingControls: option(bool)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rvbl,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r8vt, string) => 'any_rjva
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rxzr, string) => 'any_rce5
                },"showSortingControls": bool,"sortingEnabled": bool,"sortingDirection": sortingDirection,"onSort": ({.
                    "direction": [ | `Any('any_rg2u) | `Enum(direction_enum)  ],"keepOther": bool
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
                [@bs.obj] external makeProps : (~contentComponent: 'any_r1eu=?,
~toggleCellComponent: 'any_r1ov=?,
~cellComponent: 'any_rkhm=?,
~rowComponent: 'any_rsjl=?,
~toggleColumnWidth: 'number_h=?,
~rowHeight: 'number_o=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableRowDetail";
                let make = (
                    ~contentComponent: option(({.
                    "row": 'any_rpkd
                }) => ReasonReact.reactElement)=?,
~toggleCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rz6w,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rzqz, string) => 'any_r6zo
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_rxxp,"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rb10,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rd7u, string) => 'any_r1rm
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r6e1,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rllm,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_rcpn
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
                [@bs.obj] external makeProps : (~headerCellComponent: 'any_rcyv=?,
~cellComponent: 'any_rvj7=?,
~rowComponent: 'genericCallback=?,
~highlightRow: bool=?,
~selectByRowClick: bool=?,
~showSelectAll: bool=?,
~showSelectionColumn: bool=?,
~selectionColumnWidth: 'number_p=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableSelection";
                let make = (
                    ~headerCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r4k6,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rhaa, string) => 'any_rbg1
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"disabled": bool,"allSelected": bool,"someSelected": bool,"onToggle": (bool) => unit
                }) => ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rv7w,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r9u3, string) => 'any_rb5f
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_ra0y,"selected": bool,"onToggle": unit => unit
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
~totalRowComponent: 'any_rt02=?,
~groupRowComponent: 'any_r5l2=?,
~treeRowComponent: 'any_rrh5=?,
~totalCellComponent: 'any_rlv1=?,
~groupCellComponent: 'any_r5o4=?,
~treeCellComponent: 'any_rwfh=?,
~treeColumnCellComponent: 'any_rcrk=?,
~treeColumnContentComponent: 'any_re7j=?,
~treeColumnIndentComponent: 'any_rzzk=?,
~itemComponent: ReasonReact.reactElement=?,
~messages: 'any_rdco=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableSummaryRow";
                let make = (
                    ~formatlessSummaryTypes: option(array(string))=?,
~totalRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~groupRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~treeRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~totalCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r289,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rua6, string) => 'any_rld3
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_riwt, string) => 'any_rtxo
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~groupCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rlce,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r6bw, string) => 'any_ream
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r9md, string) => 'any_rs9u
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r8nj,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rzj8, string) => 'any_rreq
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_ru0n, string) => 'any_r1eb
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeColumnCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rz8s,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r6jw, string) => 'any_rsv0
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_ruxt, string) => 'any_rdo8
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
~cellComponent: 'any_rpzv=?,
~indentComponent: 'any_ru8j=?,
~expandButtonComponent: 'any_r4ma=?,
~checkboxComponent: 'any_rjci=?,
~contentComponent: 'any_r5dm=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "TableTreeColumn";
                let make = (
                    ~for_: option(string)=?,
~showSelectionControls: option(bool)=?,
~showSelectAll: option(bool)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rhhv,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rj2l, string) => 'any_riar
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"value": 'any_rm1q,"row": 'any_rpwa,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rbfy, string) => 'any_rzzm
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
~cellComponent: 'any_r1nd=?,
~rowComponent: 'any_ri7z=?,
~noDataCellComponent: 'any_raeb=?,
~noDataRowComponent: 'any_rus0=?,
~stubRowComponent: 'any_r8sw=?,
~stubCellComponent: 'any_rmwp=?,
~stubHeaderCellComponent: 'any_rn04=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~messages: 'any_rbwa=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "Table";
                let make = (
                    ~layoutComponent: option('genericCallback)=?,
~tableComponent: option(ReasonReact.reactElement)=?,
~headComponent: option(ReasonReact.reactElement)=?,
~bodyComponent: option(ReasonReact.reactElement)=?,
~footerComponent: option(ReasonReact.reactElement)=?,
~containerComponent: option(ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r3d3,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_radq, string) => 'any_r3hx
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"value": 'any_rvyz,"row": 'any_rlyl,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r7ya, string) => 'any_r5pe
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rvba,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_rb6h
                }) => ReasonReact.reactElement)=?,
~noDataCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rtj5,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rkkx, string) => 'any_rgtn
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~noDataRowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rq2o,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~stubRowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rmm8,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~stubCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r8to,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rn16, string) => 'any_ramj
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~stubHeaderCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rm50,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rufd, string) => 'any_rkge
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
                
                [@bs.obj] external makeProps : (~rootComponent: 'any_r7v4=?,
~flexibleSpaceComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "Toolbar";
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
                
                [@bs.obj] external makeProps : (~estimatedRowHeight: 'number_c=?,
~height: 'union_rd25=?,
~headTableComponent: 'genericCallback=?,
~footerTableComponent: 'genericCallback=?,
~messages: 'any_rzur=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-bootstrap3"] external reactClass : ReasonReact.reactClass = "VirtualTable";
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
        