/* eslint-disable no-useless-computed-key */
import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles(theme => ({
    modal: {
        display: 'flex',
        justifyContent: 'center',
        alignItems: 'center',
        borderRadius: '10px'
    },
    Paper: {
        display: 'flex',
        height: "max-content",
        width: "330px",
        flexDirection: "column"
    },
    Bar: {
        display: "flex",
        justifyContent: "space-between",
        alignItems: "center",
    },
    Title: {
        display: 'flex',
        marginLeft: "auto",
        marginRight: "auto",
        marginTop: "5px",
        marginBottom: "10px",
        maxWidth: "80vw",
        textAlign: "center",
    },
    Divider: {
        marginRight: "30px",
        marginLeft: "30px",
    },
    Body: {
        minHeight: "425px",
        display: "flex",
        position: "relative",
        flexDirection: "column",
        alignContent: "center",
        justifyContent: "center",
    },
    ItemInput: {
        marginTop: "15px",
        marginBottom: "15px",
        marginLeft: "auto",
        marginRight: "auto",
        height: "30px",
        width: "180px",
    }
  })
);

export default useStyles;