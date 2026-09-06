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
        minWidth: "max-content",
        maxWidth: "80vw",
        flexDirection: "column"
    },
    Bar: {
        display: "flex",
        justifyContent: "space-between",
        alignItems: "center",
        maxWidth: "80vw",
        textAlign: "center",
    },
    Title: {
        display: 'flex',
        margin: "auto",
    },
    Divider: {
        marginRight: "30px",
        marginLeft: "30px",
    },
    Body: {
        maxHeight: "90vh",
        minHeight: "425px",
        overflowY: "auto",
        overflowX: "hidden",
    }
  })
);

export default useStyles;