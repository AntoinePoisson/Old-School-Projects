/* eslint-disable no-useless-computed-key */
import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles(theme => ({
    root: {
        backgroundImage: `url(https://source.unsplash.com/random/${document.getElementById("app").offsetWidth}x${document.getElementById("app").offsetHeight})`,
        backgroundSize: "100% 100%",
        position: "relative",
        display: "flex",
        alignItems: "center",
        flexDirection: "column",
        justifyContent: "center"
    },
    block: {
        minWidth: "300px",
        minHeight: "max-content",
        overflow: "hidden",
        boxShadow: "0px 1px 3px 0px rgba(0, 0, 0, 0.2),0px 1px 1px 0px rgba(0, 0, 0, 0.14),0px 2px 1px -1px rgba(0, 0, 0, 0.12)",
        borderRadius: "4px",
        backgroundColor: "#fff",
        display: "block",
    },
    title: {
        marginTop: "10px",
        display: "flex",
        position: "relative",
        flexDirection: "column",
        alignItems: "center",
        justifyContent: "center",
    },
    divider: {
        marginRight: "30px",
        marginLeft: "30px",
    },
    tierButton: {
        backgroundColor: "#ffb36f",
        height: "20px",
        marginLeft: "20px",
        fontSize: "12px",
    },
    switcher: {
        display: "flex",
        position: "relative",
        flexDirection: "column",
        alignItems: "center",
        justifyContent: "center",
        height: "20px",
        width: "70px",
        fontSize: "12px",
        marginBottom: "5px",
        marginLeft: "auto",
        marginRight: "20px",
        marginTop: "5px",
        backgroundColor: "white"
    },
    form: {
        display: "flex",
        position: "relative",
        flexDirection: "column",
        alignItems: "center",
        justifyContent: "center",
    },
    formItem: {
        marginTop: "5px",
        marginBottom: "5px",
    },
    formItemInput: {
        width: "215px",
        '&.MuiInput-formControl': {
            marginTop: "15px",
            height: "30px",
        }
    },
    formItemButton: {
        marginTop: "10px",
        marginBottom: "10px",
    },
    spinner: {
        width: "60px !important",
        height: "60px !important",
        margin: "auto",
        display: "flex",
        padding: "40px",
    },
  })
);

export default useStyles;