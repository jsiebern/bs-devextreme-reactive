// Generated by BUCKLESCRIPT VERSION 2.2.2, PLEASE EDIT WITH CARE
'use strict';

var Js_option = require("bs-platform/lib/js/js_option.js");
var Js_boolean = require("bs-platform/lib/js/js_boolean.js");
var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");
var DxReactGridBootstrap3 = require("@devexpress/dx-react-grid-bootstrap3");

function unwrapValue(param) {
  var variant = param[0];
  if (variant >= 758940238) {
    if (variant !== 770676513) {
      if (variant >= 1034997432) {
        throw [
              Caml_builtin_exceptions.assert_failure,
              [
                "GridBootstrap3.re",
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
              "GridBootstrap3.re",
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
            "GridBootstrap3.re",
            19,
            18
          ]
        ];
  }
}

function convertMessages(madeObj) {
  var returnObj = { };
  if (madeObj) {
    returnObj["showColumnChooser"] = madeObj[0]["showColumnChooser"];
  }
  return /* Some */[returnObj];
}

function make(overlayComponent, containerComponent, itemComponent, toggleButtonComponent, messages, children) {
  var tmp = { };
  if (overlayComponent) {
    tmp.overlayComponent = overlayComponent[0];
  }
  if (containerComponent) {
    tmp.containerComponent = containerComponent[0];
  }
  if (itemComponent) {
    tmp.itemComponent = itemComponent[0];
  }
  if (toggleButtonComponent) {
    tmp.toggleButtonComponent = toggleButtonComponent[0];
  }
  var tmp$1 = convertMessages(messages);
  if (tmp$1) {
    tmp.messages = tmp$1[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.ColumnChooser, tmp, children);
}

var ColumnChooser = /* module */[
  /* convertMessages */convertMessages,
  /* make */make
];

function make$1(containerComponent, columnComponent, children) {
  var tmp = { };
  if (containerComponent) {
    tmp.containerComponent = containerComponent[0];
  }
  if (columnComponent) {
    tmp.columnComponent = columnComponent[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.DragDropProvider, tmp, children);
}

var DragDropProvider = /* module */[/* make */make$1];

function convertColumns(madeObj) {
  var returnObj = { };
  returnObj["name"] = madeObj["name"];
  returnObj["title"] = madeObj["title"];
  returnObj["getCellValue"] = madeObj["getCellValue"];
  return returnObj;
}

function make$2(rows, getRowId, getCellValue, columns, rootComponent, children) {
  var tmp = { };
  var tmp$1 = Js_option.map((function (v) {
          return v.map((function (item) {
                        return item;
                      }));
        }), rows);
  if (tmp$1) {
    tmp.rows = tmp$1[0];
  }
  if (getRowId) {
    tmp.getRowId = getRowId[0];
  }
  if (getCellValue) {
    tmp.getCellValue = getCellValue[0];
  }
  var tmp$2 = Js_option.map((function (v) {
          return v.map(convertColumns);
        }), columns);
  if (tmp$2) {
    tmp.columns = tmp$2[0];
  }
  if (rootComponent) {
    tmp.rootComponent = rootComponent[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.Grid, tmp, children);
}

var Grid = /* module */[
  /* convertColumns */convertColumns,
  /* make */make$2
];

var jsMapperConstantArray = /* array */[
  /* tuple */[
    3258129,
    "asc"
  ],
  /* tuple */[
    759138929,
    "desc"
  ]
];

function sortingDirectionToJs(param) {
  return Js_mapperRt.binarySearch(2, param, jsMapperConstantArray);
}

function sortingDirectionFromJs(param) {
  return Js_mapperRt.revSearch(2, jsMapperConstantArray, param);
}

var jsMapperConstantArray$1 = /* array */[
  /* tuple */[
    3258129,
    "asc"
  ],
  /* tuple */[
    759138929,
    "desc"
  ]
];

function ryvjToJs(param) {
  return Js_mapperRt.binarySearch(2, param, jsMapperConstantArray$1);
}

function ryvjFromJs(param) {
  return Js_mapperRt.revSearch(2, jsMapperConstantArray$1, param);
}

function convertMessages$1(madeObj) {
  var returnObj = { };
  if (madeObj) {
    returnObj["groupByColumn"] = madeObj[0]["groupByColumn"];
  }
  return /* Some */[returnObj];
}

function make$3(showSortingControls, showGroupingControls, layoutComponent, containerComponent, itemComponent, emptyMessageComponent, messages, children) {
  var tmp = { };
  var tmp$1 = Js_option.map(Js_boolean.to_js_boolean, showSortingControls);
  if (tmp$1) {
    tmp.showSortingControls = tmp$1[0];
  }
  var tmp$2 = Js_option.map(Js_boolean.to_js_boolean, showGroupingControls);
  if (tmp$2) {
    tmp.showGroupingControls = tmp$2[0];
  }
  if (layoutComponent) {
    tmp.layoutComponent = layoutComponent[0];
  }
  if (containerComponent) {
    tmp.containerComponent = containerComponent[0];
  }
  if (itemComponent) {
    tmp.itemComponent = itemComponent[0];
  }
  if (emptyMessageComponent) {
    tmp.emptyMessageComponent = emptyMessageComponent[0];
  }
  var tmp$3 = convertMessages$1(messages);
  if (tmp$3) {
    tmp.messages = tmp$3[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.GroupingPanel, tmp, children);
}

var GroupingPanel = /* module */[
  /* sortingDirectionToJs */sortingDirectionToJs,
  /* sortingDirectionFromJs */sortingDirectionFromJs,
  /* ryvjToJs */ryvjToJs,
  /* ryvjFromJs */ryvjFromJs,
  /* convertMessages */convertMessages$1,
  /* make */make$3
];

function convertMessages$2(madeObj) {
  var returnObj = { };
  if (madeObj) {
    var madeObj$1 = madeObj[0];
    returnObj["showAll"] = madeObj$1["showAll"];
    returnObj["rowsPerPage"] = madeObj$1["rowsPerPage"];
    returnObj["info"] = madeObj$1["info"];
  }
  return /* Some */[returnObj];
}

function make$4(pageSizes, containerComponent, messages, children) {
  var tmp = { };
  if (pageSizes) {
    tmp.pageSizes = pageSizes[0];
  }
  if (containerComponent) {
    tmp.containerComponent = containerComponent[0];
  }
  var tmp$1 = convertMessages$2(messages);
  if (tmp$1) {
    tmp.messages = tmp$1[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.PagingPanel, tmp, children);
}

var PagingPanel = /* module */[
  /* convertMessages */convertMessages$2,
  /* make */make$4
];

function convertMessages$3(madeObj) {
  var returnObj = { };
  if (madeObj) {
    returnObj["searchPlaceholder"] = madeObj[0]["searchPlaceholder"];
  }
  return /* Some */[returnObj];
}

function make$5(inputComponent, messages, children) {
  var tmp = { };
  if (inputComponent) {
    tmp.inputComponent = inputComponent[0];
  }
  var tmp$1 = convertMessages$3(messages);
  if (tmp$1) {
    tmp.messages = tmp$1[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.SearchPanel, tmp, children);
}

var SearchPanel = /* module */[
  /* convertMessages */convertMessages$3,
  /* make */make$5
];

function make$6(order, defaultOrder, onOrderChange, tableContainerComponent, rowComponent, cellComponent, children) {
  var tmp = { };
  if (order) {
    tmp.order = order[0];
  }
  if (defaultOrder) {
    tmp.defaultOrder = defaultOrder[0];
  }
  if (onOrderChange) {
    tmp.onOrderChange = onOrderChange[0];
  }
  if (tableContainerComponent) {
    tmp.tableContainerComponent = tableContainerComponent[0];
  }
  if (rowComponent) {
    tmp.rowComponent = rowComponent[0];
  }
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableColumnReordering, tmp, children);
}

var TableColumnReordering = /* module */[/* make */make$6];

function convertDefaultColumnWidths(madeObj) {
  var returnObj = { };
  returnObj["columnName"] = madeObj["columnName"];
  returnObj["width"] = unwrapValue(madeObj["width"]);
  return returnObj;
}

function convertColumnWidths(madeObj) {
  var returnObj = { };
  returnObj["columnName"] = madeObj["columnName"];
  returnObj["width"] = unwrapValue(madeObj["width"]);
  return returnObj;
}

function make$7(defaultColumnWidths, columnWidths, onColumnWidthsChange, children) {
  var tmp = { };
  var tmp$1 = Js_option.map((function (v) {
          return v.map(convertDefaultColumnWidths);
        }), defaultColumnWidths);
  if (tmp$1) {
    tmp.defaultColumnWidths = tmp$1[0];
  }
  var tmp$2 = Js_option.map((function (v) {
          return v.map(convertColumnWidths);
        }), columnWidths);
  if (tmp$2) {
    tmp.columnWidths = tmp$2[0];
  }
  if (onColumnWidthsChange) {
    tmp.onColumnWidthsChange = onColumnWidthsChange[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableColumnResizing, tmp, children);
}

var TableColumnResizing = /* module */[
  /* convertDefaultColumnWidths */convertDefaultColumnWidths,
  /* convertColumnWidths */convertColumnWidths,
  /* make */make$7
];

function convertMessages$4(madeObj) {
  var returnObj = { };
  if (madeObj) {
    returnObj["noColumns"] = madeObj[0]["noColumns"];
  }
  return /* Some */[returnObj];
}

function convertColumnExtensions(madeObj) {
  var returnObj = { };
  returnObj["columnName"] = madeObj["columnName"];
  returnObj["togglingEnabled"] = Js_boolean.to_js_boolean(madeObj["togglingEnabled"]);
  return returnObj;
}

function make$8(hiddenColumnNames, defaultHiddenColumnNames, emptyMessageComponent, onHiddenColumnNamesChange, messages, columnExtensions, columnTogglingEnabled, children) {
  var tmp = { };
  if (hiddenColumnNames) {
    tmp.hiddenColumnNames = hiddenColumnNames[0];
  }
  if (defaultHiddenColumnNames) {
    tmp.defaultHiddenColumnNames = defaultHiddenColumnNames[0];
  }
  if (emptyMessageComponent) {
    tmp.emptyMessageComponent = emptyMessageComponent[0];
  }
  if (onHiddenColumnNamesChange) {
    tmp.onHiddenColumnNamesChange = onHiddenColumnNamesChange[0];
  }
  var tmp$1 = convertMessages$4(messages);
  if (tmp$1) {
    tmp.messages = tmp$1[0];
  }
  var tmp$2 = Js_option.map((function (v) {
          return v.map(convertColumnExtensions);
        }), columnExtensions);
  if (tmp$2) {
    tmp.columnExtensions = tmp$2[0];
  }
  var tmp$3 = Js_option.map(Js_boolean.to_js_boolean, columnTogglingEnabled);
  if (tmp$3) {
    tmp.columnTogglingEnabled = tmp$3[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableColumnVisibility, tmp, children);
}

var TableColumnVisibility = /* module */[
  /* convertMessages */convertMessages$4,
  /* convertColumnExtensions */convertColumnExtensions,
  /* make */make$8
];

var jsMapperConstantArray$2 = /* array */[
  /* tuple */[
    -57574468,
    "right"
  ],
  /* tuple */[
    847852583,
    "left"
  ],
  /* tuple */[
    980392437,
    "center"
  ]
];

function alignToJs(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$2);
}

function alignFromJs(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$2, param);
}

var jsMapperConstantArray$3 = /* array */[
  /* tuple */[
    -322412134,
    "cancel"
  ],
  /* tuple */[
    -71113705,
    "commit"
  ],
  /* tuple */[
    3254785,
    "add"
  ],
  /* tuple */[
    527250507,
    "delete"
  ],
  /* tuple */[
    770176554,
    "edit"
  ]
];

function idToJs(param) {
  return Js_mapperRt.binarySearch(5, param, jsMapperConstantArray$3);
}

function idFromJs(param) {
  return Js_mapperRt.revSearch(5, jsMapperConstantArray$3, param);
}

function convertMessages$5(madeObj) {
  var returnObj = { };
  if (madeObj) {
    var madeObj$1 = madeObj[0];
    returnObj["addCommand"] = madeObj$1["addCommand"];
    returnObj["editCommand"] = madeObj$1["editCommand"];
    returnObj["deleteCommand"] = madeObj$1["deleteCommand"];
    returnObj["commitCommand"] = madeObj$1["commitCommand"];
    returnObj["cancelCommand"] = madeObj$1["cancelCommand"];
  }
  return /* Some */[returnObj];
}

function make$9(cellComponent, headerCellComponent, commandComponent, showAddCommand, showEditCommand, showDeleteCommand, width, messages, children) {
  var tmp = { };
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  if (headerCellComponent) {
    tmp.headerCellComponent = headerCellComponent[0];
  }
  if (commandComponent) {
    tmp.commandComponent = commandComponent[0];
  }
  var tmp$1 = Js_option.map(Js_boolean.to_js_boolean, showAddCommand);
  if (tmp$1) {
    tmp.showAddCommand = tmp$1[0];
  }
  var tmp$2 = Js_option.map(Js_boolean.to_js_boolean, showEditCommand);
  if (tmp$2) {
    tmp.showEditCommand = tmp$2[0];
  }
  var tmp$3 = Js_option.map(Js_boolean.to_js_boolean, showDeleteCommand);
  if (tmp$3) {
    tmp.showDeleteCommand = tmp$3[0];
  }
  var tmp$4 = Js_option.map(unwrapValue, width);
  if (tmp$4) {
    tmp.width = tmp$4[0];
  }
  var tmp$5 = convertMessages$5(messages);
  if (tmp$5) {
    tmp.messages = tmp$5[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableEditColumn, tmp, children);
}

var TableEditColumn = /* module */[
  /* alignToJs */alignToJs,
  /* alignFromJs */alignFromJs,
  /* idToJs */idToJs,
  /* idFromJs */idFromJs,
  /* convertMessages */convertMessages$5,
  /* make */make$9
];

var jsMapperConstantArray$4 = /* array */[
  /* tuple */[
    -57574468,
    "right"
  ],
  /* tuple */[
    847852583,
    "left"
  ],
  /* tuple */[
    980392437,
    "center"
  ]
];

function alignToJs$1(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$4);
}

function alignFromJs$1(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$4, param);
}

function make$10(rowHeight, cellComponent, rowComponent, children) {
  var tmp = { };
  var tmp$1 = Js_option.map(unwrapValue, rowHeight);
  if (tmp$1) {
    tmp.rowHeight = tmp$1[0];
  }
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  if (rowComponent) {
    tmp.rowComponent = rowComponent[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableEditRow, tmp, children);
}

var TableEditRow = /* module */[
  /* alignToJs */alignToJs$1,
  /* alignFromJs */alignFromJs$1,
  /* make */make$10
];

function convertMessages$6(madeObj) {
  var returnObj = { };
  if (madeObj) {
    returnObj["filterPlaceholder"] = madeObj[0]["filterPlaceholder"];
  }
  return /* Some */[returnObj];
}

var jsMapperConstantArray$5 = /* array */[
  /* tuple */[
    -57574468,
    "right"
  ],
  /* tuple */[
    847852583,
    "left"
  ],
  /* tuple */[
    980392437,
    "center"
  ]
];

function alignToJs$2(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$5);
}

function alignFromJs$2(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$5, param);
}

function make$11(rowHeight, messages, cellComponent, rowComponent, children) {
  var tmp = { };
  var tmp$1 = Js_option.map(unwrapValue, rowHeight);
  if (tmp$1) {
    tmp.rowHeight = tmp$1[0];
  }
  var tmp$2 = convertMessages$6(messages);
  if (tmp$2) {
    tmp.messages = tmp$2[0];
  }
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  if (rowComponent) {
    tmp.rowComponent = rowComponent[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableFilterRow, tmp, children);
}

var TableFilterRow = /* module */[
  /* convertMessages */convertMessages$6,
  /* alignToJs */alignToJs$2,
  /* alignFromJs */alignFromJs$2,
  /* make */make$11
];

var jsMapperConstantArray$6 = /* array */[
  /* tuple */[
    -57574468,
    "right"
  ],
  /* tuple */[
    847852583,
    "left"
  ],
  /* tuple */[
    980392437,
    "center"
  ]
];

function alignToJs$3(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$6);
}

function alignFromJs$3(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$6, param);
}

function convertColumnExtensions$1(madeObj) {
  var returnObj = { };
  returnObj["columnName"] = madeObj["columnName"];
  returnObj["showWhenGrouped"] = Js_option.map(Js_boolean.to_js_boolean, madeObj["showWhenGrouped"]);
  return returnObj;
}

function make$12(cellComponent, rowComponent, indentCellComponent, indentColumnWidth, showColumnsWhenGrouped, columnExtensions, children) {
  var tmp = { };
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  if (rowComponent) {
    tmp.rowComponent = rowComponent[0];
  }
  if (indentCellComponent) {
    tmp.indentCellComponent = indentCellComponent[0];
  }
  var tmp$1 = Js_option.map(unwrapValue, indentColumnWidth);
  if (tmp$1) {
    tmp.indentColumnWidth = tmp$1[0];
  }
  var tmp$2 = Js_option.map(Js_boolean.to_js_boolean, showColumnsWhenGrouped);
  if (tmp$2) {
    tmp.showColumnsWhenGrouped = tmp$2[0];
  }
  var tmp$3 = Js_option.map((function (v) {
          return v.map(convertColumnExtensions$1);
        }), columnExtensions);
  if (tmp$3) {
    tmp.columnExtensions = tmp$3[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableGroupRow, tmp, children);
}

var TableGroupRow = /* module */[
  /* alignToJs */alignToJs$3,
  /* alignFromJs */alignFromJs$3,
  /* convertColumnExtensions */convertColumnExtensions$1,
  /* make */make$12
];

var jsMapperConstantArray$7 = /* array */[
  /* tuple */[
    -57574468,
    "right"
  ],
  /* tuple */[
    847852583,
    "left"
  ],
  /* tuple */[
    980392437,
    "center"
  ]
];

function alignToJs$4(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$7);
}

function alignFromJs$4(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$7, param);
}

var jsMapperConstantArray$8 = /* array */[
  /* tuple */[
    3258129,
    "asc"
  ],
  /* tuple */[
    759138929,
    "desc"
  ]
];

function sortingDirectionToJs$1(param) {
  return Js_mapperRt.binarySearch(2, param, jsMapperConstantArray$8);
}

function sortingDirectionFromJs$1(param) {
  return Js_mapperRt.revSearch(2, jsMapperConstantArray$8, param);
}

var jsMapperConstantArray$9 = /* array */[
  /* tuple */[
    3258129,
    "asc"
  ],
  /* tuple */[
    759138929,
    "desc"
  ]
];

function rcesToJs(param) {
  return Js_mapperRt.binarySearch(2, param, jsMapperConstantArray$9);
}

function rcesFromJs(param) {
  return Js_mapperRt.revSearch(2, jsMapperConstantArray$9, param);
}

function convertMessages$7(madeObj) {
  var returnObj = { };
  if (madeObj) {
    returnObj["sortingHint"] = madeObj[0]["sortingHint"];
  }
  return /* Some */[returnObj];
}

function make$13(showSortingControls, showGroupingControls, cellComponent, rowComponent, messages, children) {
  var tmp = { };
  var tmp$1 = Js_option.map(Js_boolean.to_js_boolean, showSortingControls);
  if (tmp$1) {
    tmp.showSortingControls = tmp$1[0];
  }
  var tmp$2 = Js_option.map(Js_boolean.to_js_boolean, showGroupingControls);
  if (tmp$2) {
    tmp.showGroupingControls = tmp$2[0];
  }
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  if (rowComponent) {
    tmp.rowComponent = rowComponent[0];
  }
  var tmp$3 = convertMessages$7(messages);
  if (tmp$3) {
    tmp.messages = tmp$3[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableHeaderRow, tmp, children);
}

var TableHeaderRow = /* module */[
  /* alignToJs */alignToJs$4,
  /* alignFromJs */alignFromJs$4,
  /* sortingDirectionToJs */sortingDirectionToJs$1,
  /* sortingDirectionFromJs */sortingDirectionFromJs$1,
  /* rcesToJs */rcesToJs,
  /* rcesFromJs */rcesFromJs,
  /* convertMessages */convertMessages$7,
  /* make */make$13
];

var jsMapperConstantArray$10 = /* array */[
  /* tuple */[
    -57574468,
    "right"
  ],
  /* tuple */[
    847852583,
    "left"
  ],
  /* tuple */[
    980392437,
    "center"
  ]
];

function alignToJs$5(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$10);
}

function alignFromJs$5(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$10, param);
}

function make$14(contentComponent, toggleCellComponent, cellComponent, rowComponent, toggleColumnWidth, rowHeight, children) {
  var tmp = { };
  if (contentComponent) {
    tmp.contentComponent = contentComponent[0];
  }
  if (toggleCellComponent) {
    tmp.toggleCellComponent = toggleCellComponent[0];
  }
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  if (rowComponent) {
    tmp.rowComponent = rowComponent[0];
  }
  var tmp$1 = Js_option.map(unwrapValue, toggleColumnWidth);
  if (tmp$1) {
    tmp.toggleColumnWidth = tmp$1[0];
  }
  var tmp$2 = Js_option.map(unwrapValue, rowHeight);
  if (tmp$2) {
    tmp.rowHeight = tmp$2[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableRowDetail, tmp, children);
}

var TableRowDetail = /* module */[
  /* alignToJs */alignToJs$5,
  /* alignFromJs */alignFromJs$5,
  /* make */make$14
];

var jsMapperConstantArray$11 = /* array */[
  /* tuple */[
    -57574468,
    "right"
  ],
  /* tuple */[
    847852583,
    "left"
  ],
  /* tuple */[
    980392437,
    "center"
  ]
];

function alignToJs$6(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$11);
}

function alignFromJs$6(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$11, param);
}

function make$15(headerCellComponent, cellComponent, rowComponent, highlightRow, selectByRowClick, showSelectAll, showSelectionColumn, selectionColumnWidth, children) {
  var tmp = { };
  if (headerCellComponent) {
    tmp.headerCellComponent = headerCellComponent[0];
  }
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  if (rowComponent) {
    tmp.rowComponent = rowComponent[0];
  }
  var tmp$1 = Js_option.map(Js_boolean.to_js_boolean, highlightRow);
  if (tmp$1) {
    tmp.highlightRow = tmp$1[0];
  }
  var tmp$2 = Js_option.map(Js_boolean.to_js_boolean, selectByRowClick);
  if (tmp$2) {
    tmp.selectByRowClick = tmp$2[0];
  }
  var tmp$3 = Js_option.map(Js_boolean.to_js_boolean, showSelectAll);
  if (tmp$3) {
    tmp.showSelectAll = tmp$3[0];
  }
  var tmp$4 = Js_option.map(Js_boolean.to_js_boolean, showSelectionColumn);
  if (tmp$4) {
    tmp.showSelectionColumn = tmp$4[0];
  }
  var tmp$5 = Js_option.map(unwrapValue, selectionColumnWidth);
  if (tmp$5) {
    tmp.selectionColumnWidth = tmp$5[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.TableSelection, tmp, children);
}

var TableSelection = /* module */[
  /* alignToJs */alignToJs$6,
  /* alignFromJs */alignFromJs$6,
  /* make */make$15
];

var jsMapperConstantArray$12 = /* array */[
  /* tuple */[
    -57574468,
    "right"
  ],
  /* tuple */[
    847852583,
    "left"
  ],
  /* tuple */[
    980392437,
    "center"
  ]
];

function alignToJs$7(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$12);
}

function alignFromJs$7(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$12, param);
}

function convertColumnExtensions$2(madeObj) {
  var returnObj = { };
  returnObj["columnName"] = madeObj["columnName"];
  returnObj["width"] = Js_option.map(unwrapValue, madeObj["width"]);
  returnObj["align"] = Js_option.map((function (v) {
          return Js_mapperRt.binarySearch(3, v, jsMapperConstantArray$12);
        }), madeObj["align"]);
  return returnObj;
}

function convertMessages$8(madeObj) {
  var returnObj = { };
  if (madeObj) {
    returnObj["noData"] = madeObj[0]["noData"];
  }
  return /* Some */[returnObj];
}

function make$16(layoutComponent, tableComponent, headComponent, bodyComponent, containerComponent, cellComponent, rowComponent, noDataCellComponent, noDataRowComponent, stubCellComponent, stubHeaderCellComponent, columnExtensions, messages, fixedHeaderComponent, children) {
  var tmp = { };
  if (layoutComponent) {
    tmp.layoutComponent = layoutComponent[0];
  }
  if (tableComponent) {
    tmp.tableComponent = tableComponent[0];
  }
  if (headComponent) {
    tmp.headComponent = headComponent[0];
  }
  if (bodyComponent) {
    tmp.bodyComponent = bodyComponent[0];
  }
  if (containerComponent) {
    tmp.containerComponent = containerComponent[0];
  }
  if (cellComponent) {
    tmp.cellComponent = cellComponent[0];
  }
  if (rowComponent) {
    tmp.rowComponent = rowComponent[0];
  }
  if (noDataCellComponent) {
    tmp.noDataCellComponent = noDataCellComponent[0];
  }
  if (noDataRowComponent) {
    tmp.noDataRowComponent = noDataRowComponent[0];
  }
  if (stubCellComponent) {
    tmp.stubCellComponent = stubCellComponent[0];
  }
  if (stubHeaderCellComponent) {
    tmp.stubHeaderCellComponent = stubHeaderCellComponent[0];
  }
  var tmp$1 = Js_option.map((function (v) {
          return v.map(convertColumnExtensions$2);
        }), columnExtensions);
  if (tmp$1) {
    tmp.columnExtensions = tmp$1[0];
  }
  var tmp$2 = convertMessages$8(messages);
  if (tmp$2) {
    tmp.messages = tmp$2[0];
  }
  if (fixedHeaderComponent) {
    tmp.fixedHeaderComponent = fixedHeaderComponent[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.Table, tmp, children);
}

var Table = /* module */[
  /* alignToJs */alignToJs$7,
  /* alignFromJs */alignFromJs$7,
  /* convertColumnExtensions */convertColumnExtensions$2,
  /* convertMessages */convertMessages$8,
  /* make */make$16
];

function make$17(rootComponent, flexibleSpaceComponent, children) {
  var tmp = { };
  if (rootComponent) {
    tmp.rootComponent = rootComponent[0];
  }
  if (flexibleSpaceComponent) {
    tmp.flexibleSpaceComponent = flexibleSpaceComponent[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.Toolbar, tmp, children);
}

var Toolbar = /* module */[/* make */make$17];

function convertMessages$9(madeObj) {
  var returnObj = { };
  if (madeObj) {
    returnObj["noData"] = madeObj[0]["noData"];
  }
  return /* Some */[returnObj];
}

function make$18(estimatedRowHeight, height, messages, children) {
  var tmp = { };
  var tmp$1 = Js_option.map(unwrapValue, estimatedRowHeight);
  if (tmp$1) {
    tmp.estimatedRowHeight = tmp$1[0];
  }
  var tmp$2 = Js_option.map(unwrapValue, height);
  if (tmp$2) {
    tmp.height = tmp$2[0];
  }
  var tmp$3 = convertMessages$9(messages);
  if (tmp$3) {
    tmp.messages = tmp$3[0];
  }
  return ReasonReact.wrapJsForReason(DxReactGridBootstrap3.VirtualTable, tmp, children);
}

var VirtualTable = /* module */[
  /* convertMessages */convertMessages$9,
  /* make */make$18
];

exports.unwrapValue = unwrapValue;
exports.ColumnChooser = ColumnChooser;
exports.DragDropProvider = DragDropProvider;
exports.Grid = Grid;
exports.GroupingPanel = GroupingPanel;
exports.PagingPanel = PagingPanel;
exports.SearchPanel = SearchPanel;
exports.TableColumnReordering = TableColumnReordering;
exports.TableColumnResizing = TableColumnResizing;
exports.TableColumnVisibility = TableColumnVisibility;
exports.TableEditColumn = TableEditColumn;
exports.TableEditRow = TableEditRow;
exports.TableFilterRow = TableFilterRow;
exports.TableGroupRow = TableGroupRow;
exports.TableHeaderRow = TableHeaderRow;
exports.TableRowDetail = TableRowDetail;
exports.TableSelection = TableSelection;
exports.Table = Table;
exports.Toolbar = Toolbar;
exports.VirtualTable = VirtualTable;
/* ReasonReact Not a pure module */
