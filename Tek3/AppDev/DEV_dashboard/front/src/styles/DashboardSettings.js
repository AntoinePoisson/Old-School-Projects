/* eslint-disable no-useless-computed-key */
import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles(theme => ({
    root: {
        position: "relative",
        display: "flex",
        flexDirection: "column",
        height: "100%",
        width: "100%",
        backgroundColor: "#eceaea",
    },
    title: {
        marginLeft: "10px",
    },
    text: {
        height: "100%",
        width: "auto",
        overflowY: "auto",
        background: "white",
        border: "1px solid #000",
        margin: "20px",
    },
    button: {
        width: "300px",
        marginBottom: "10px",
    }
  })
);

export default useStyles;