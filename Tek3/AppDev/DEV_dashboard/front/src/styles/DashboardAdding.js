/* eslint-disable no-useless-computed-key */
import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles(theme => ({
    root: {
        position: "relative",
        flexDirection: "column",
        display: "flex",
        height: "100%",
        width: "100%",
        backgroundColor: "#eceaea",
    },
    noWidget: {
        display: "flex",
        position: "relative",
        flexDirection: "column",
        alignItems: "center",
        justifyContent: "center",
        height: "100%",
        width: "100%",
    },
    Container: {
        display: "flex",
        position: "relative",
        flexDirection: "row",
        alignItems: "center",
        justifyContent: "center",
        marginTop: "5px",
        marginBottom: "5px",
        height: "100%",
        width: "auto",
        overflowY: "auto",
        overflowX: "hidden"
    },
    Wrapper: {
        minHeight: "max-content",
        maxHeight: "400px",
        margin: "10px",
        marginTop: "5px",
        marginBottom: "5px",
        borderRadius: "10px",
    },
    title: {
        marginLeft: "15px",
    },
    body: {
        overflowX: "auto",
        minHeight: "max-content",
        display: "flex",
        position: "relation",
        flexDirection: "row",
        justifyContent: "flex-start",
    },
    widget: {
        display: "flex",
        flexDirection: "column",
        justifyContent: "center",
        position: "relation",
        minHeight: "180px",
        minWidth: "180px",
        maxHeight: "210px",
        maxWidth: "210px",
        margin: "10px"
    },
    disableWidget: {
        display: "flex",
        flexDirection: "column",
        justifyContent: "center",
        position: "relation",
        minHeight: "180px",
        minWidth: "180px",
        maxHeight: "210px",
        maxWidth: "210px",
        margin: "10px",
        color: "red !important",
        boxShadow: "0px 3px 1px -2px rgb(249, 0, 0),0px 2px 2px 0px rgb(255, 0, 0),0px 1px 5px 0px rgba(253, 0, 0, 0.12) !important",
        "& .MuiPaper-root": {
            color: "red",
        },
        "& .MuiPaper-elevation2": {
            boxShadow: "0px 3px 1px -2px rgb(249, 0, 0),0px 2px 2px 0px rgb(255, 0, 0),0px 1px 5px 0px rgba(253, 0, 0, 0.12)",
        },
        "& .MuiPaper-elevation3": {
            boxShadow: "0px 3px 3px -2px rgb(255, 0, 0),0px 3px 4px 0px rgb(255, 0, 0),0px 1px 8px 0px rgba(255, 9, 9, 0.12)",
        }
    },
    disablePaper: {
        "& .MuiPaper-root": {
            color: "red",
        },
        "& .MuiPaper-elevation2": {
            boxShadow: "0px 3px 1px -2px rgb(249, 0, 0),0px 2px 2px 0px rgb(255, 0, 0),0px 1px 5px 0px rgba(253, 0, 0, 0.12)",
        },
        "& .MuiPaper-elevation3": {
            boxShadow: "0px 3px 3px -2px rgb(255, 0, 0),0px 3px 4px 0px rgb(255, 0, 0),0px 1px 8px 0px rgba(255, 9, 9, 0.12)",
        }
    },
    textItem: {
        marginLeft: "auto",
        marginRight: "auto",
        marginTop: "5px",
        marginBottom: "5px",
        textAlign: "center",
    },
    buttonItem: {
        marginLeft: "auto",
        marginRight: "auto",
        marginTop: "5px",
        marginBottom: "5px",
        border: "solid",
        borderRadius: "50px",
        borderWidth: "2px",
    },
    useless: {
        "& .MuiPaper-elevation3": {
            boxShadow: "0px 3px 3px -2px rgba(0,0,0,0.2),0px 3px 4px 0px rgba(0,0,0,0.14),0px 1px 8px 0px rgba(0,0,0,0.12)",
        }
    },
  })
);

export default useStyles;