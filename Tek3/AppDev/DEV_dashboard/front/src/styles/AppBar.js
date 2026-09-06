/* eslint-disable no-useless-computed-key */
import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles(theme => ({
    root: {
        position: "relative",
        display: "flex",
        height: "100%",
        width: "min-content",
    },
    sidebar: {
        "&.pro-sidebar": {
          width: "195px",
          minWidth: "195px",
        },
        "&.pro-sidebar.collapsed": {
          width: "80px !important",
          minWidth: "80px !important",
        }
    },
  })
);

export default useStyles;