/* eslint-disable no-useless-computed-key */
import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles(theme => ({
    root: {
        position: "relative",
        display: "flex",
        height: "100%",
        width: "100%",
    },
    menu: {
        '& .MuiPopover-paper': {
            borderRadius: "18px",
        },
        '& .MuiList-padding': {
            paddingBottom: '0px',
            paddingTop: '0px',
        },
        '& .MuiListItem-gutters': {
            paddingLeft: '3px',
            paddingRight: '3px',
            paddingBottom: '3px',
            paddingTop: '20px'
        },
        '& .MuiListItem-root.Mui-disabled': {
            opacity: '0.1'
        }
    },
    menuItem: {
        display: "inline",
    },
    menuDividerItem: {
        display: "inline",
        padding: "1px",
        paddingBottom: "25px",
    }
  })
);

export default useStyles;