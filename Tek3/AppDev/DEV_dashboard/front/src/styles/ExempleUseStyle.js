/* eslint-disable no-useless-computed-key */
import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles(theme => ({
    root: {
        paddingLeft: '5px',
        paddingRight: '5px',
        paddingTop: '5px',
        ['@media (max-width:570px)']: {
            paddingLeft: '6px',
            paddingRight: '6px'
        },
        ['@media (max-width:425px)']: {
            paddingLeft: '7px',
            paddingRight: '7px'
        }
    },
    avatarContainer: {
        padding: '2px',
        margin: 5,
        backgroundColor: theme.palette.background.avatar,
        ['@media (max-width:570px)']: {
            margin: 2
        }
    },
    avatar: {
        height: 75,
        width: 75,
        display: 'absolute',
        ['@media (max-width:570px)']: {
            height: 60,
            width: 60
        },
        ['@media (max-width:425px)']: {
            height: 55,
            width: 55
        }
    },
    spinner: {
        top: 17,
        left: 17,
        position: 'absolute',
        color: 'primary',
        ['@media (max-width:570px)']: {
            top: 9,
            left: 9
        },
        ['@media (max-width:425px)']: {
            top: 7,
            left: 7
        }
    },
    text: {
        height: 'auto',
        maxWidth: '100px',
        ['@media (max-width:570px)']: {
            maxWidth: '80px'
        },
        ['@media (max-width:425px)']: {
            maxWidth: '70px'
        }
    },
    sizeText: {
        ['@media (max-width:500px)']: {
            fontSize: '2.5vw'
        },
        ['@media (max-width:420px)']: {
            fontSize: '2.8vw'
        },
        ['@media (max-width:400px)']: {
            fontSize: '3.3vw'
        },
        ['@media (max-width:320px)']: {
            fontSize: '12px'
        }
    }
  })
);

export default useStyles;