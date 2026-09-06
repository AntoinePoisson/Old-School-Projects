import { makeStyles } from '@material-ui/core/styles';


const useStyles = makeStyles({
    root: {
        display: 'flex',
        flexDirection: 'column',
        position: 'relative',
    },
    bar: {
        paddingInline: "5px",
        paddingInlineStart: "9px",
        borderTopLeftRadius: "5px",
        borderTopRightRadius: "5px",
    },
    title: {
        marginTop: "auto",
        marginBottom: "auto",
    },
    body: {
        marginLeft: "1px",
        marginRight: "1px",
        height: "238px",
        overflowX: "hidden",
        overflowY: "auto",
    },
    input: {
        "& .fileContainer": {
            height: "187px !important",
        },
    },
   }
);

export default useStyles;