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
        width: "100%",
        overflowY: "scroll",
        overflowX: "hidden"
    },
    Wrapper: {
        minHeight: "290px",
        maxHeight: "400px",
        margin: "10px",
        marginTop: "5px",
        marginBottom: "5px",
        borderRadius: "10px",
    },
  })
);

export default useStyles;