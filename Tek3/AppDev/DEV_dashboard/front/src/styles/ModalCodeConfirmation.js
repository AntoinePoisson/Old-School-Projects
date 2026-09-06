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
        width: "370px",
        flexDirection: "column"
    },
    Title: {
        display: 'flex',
        marginLeft: "auto",
        marginRight: "auto",
        marginTop: "5px",
        marginBottom: "10px",
    },
    Divider: {
        marginRight: "30px",
        marginLeft: "30px",
    },
    Message: {
      marginTop: "10px",
        marginLeft: "30px",
        marginRight: "30px",
    },
    Input: {
        maxWidth: "170px",
        marginTop: "15px",
        marginBottom: "15px",
        marginLeft: "auto",
        marginRight: "auto",
    },
    buttonValide: {
        width: "245px",
        marginTop: "10px",
        marginBottom: "10px",
        marginLeft: "auto",
        marginRight: "auto",
    }
  })
);

export default useStyles;