import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles({
    root: {
        display: 'flex',
        flexDirection: 'column',
        justifyContent: 'center',
        alignItems: 'center',
        height: '100vh',
        width: '100vw',
        position: 'relative',
        background: 'rgb(14, 30, 37)'
    },
    paper: {
        display: 'flex',
        flexDirection: 'column',
        width: '75%',
        maxWidth: '364px',
        position: 'relative',
        padding: '24px',
        background: 'white',
        color: 'rgb(14, 30, 37)',
        borderRadius: '8px',
        boxShadow: '0 2px 4px 0 rgba(14, 30, 37, .16)'
    },
    button: {
        paddingTop: '10px'
    }
   }
);

export default useStyles;