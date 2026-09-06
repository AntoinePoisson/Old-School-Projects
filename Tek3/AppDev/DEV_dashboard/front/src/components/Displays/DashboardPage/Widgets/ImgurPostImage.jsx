import React, { useState, useEffect, useContext } from 'react';

import { Divider, Grid, IconButton, Typography } from '@material-ui/core';
import SettingsIcon from '@material-ui/icons/Settings';
import ButtonHandleCardPosition from '../../../Tools/ButtonHandleCardPosition';
import ImageUploader from 'react-images-upload';
import useStyles from '../../../../styles/WidgetTemplate';
import ModalSettingsPostImage from '../../../Modals/ImgurPostSettings';
import MySnackBar from '../../../Tools/SnackBar';
import DataContext from '../../../../contexts/dataContext';

const WidgetImagePostImage = ({index, list, setList}) => {

    const classes = useStyles();

    const [input, setInput] = useState({open: false, file: [], complete: false});
    const [snackbar, setSnackbar] = useState({message: "", type: "", recall: 0})
    const [dataState, ] = useContext(DataContext);

    useEffect(() => {
        if (input.complete !== true)
            return;
        if (input.file === undefined) {
            setInput({open: false, file: [], complete: false})
            return;
        }
        var form = new FormData();
        form.append("title", input.title);
        form.append("description", input.description);
        form.append("name", input.name);
        form.append("type", input.file[0].type);

        let blob = new Blob(input.file, {type: input.file[0].type});

        const blobToBase64 = blob => {
            const reader = new FileReader();
            reader.readAsDataURL(blob);
            return new Promise(resolve => {
              reader.onloadend = () => {
                resolve(reader.result);
              };
            });
          };

        blobToBase64(blob)
            .then(ttt => {
                form.append("image", ttt); //tt.result.splice(',')[1] //tt.result
                const myInit = {
                    method: "POST",
                    headers: new Headers({"Content-Type": 'multipart/form-data', Authorization: `Bearer ${dataState.TokenServices.Imgur}`}),
                    mode: "cors",
                    body: form,
                    cache: "default"
                };
                fetch(`https://api.imgur.com/3/image`, myInit)
                    .then(async res => {
                        const result = await res.json()
                        console.log("res", result)
                        if (result.error) {
                            setSnackbar({ message: "Failure Save Widget", type: "error", recall: snackbar.recall + 1 });
                        } else {
                            console.log("ok")
                        }
                        setInput({open: false, file: [], complete: false})
                    })
                    .catch((error) => {
                        console.log(error)
                        setInput({open: false, file: [], complete: false})
                        setSnackbar({ message: "Failure Save Widget", type: "error", recall: snackbar.recall + 1 });
                    })
            });

    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [input]);

    return (
        <Grid className={classes.root}>
            <Grid container className={classes.bar}>
                <Grid item xs={10} style={{display: "flex"}}>
                    <Typography className={classes.title} variant="h5" component="h5" style={{color: list[index].color}}>
                        { list[index].title }
                    </Typography>
                </Grid>
                <Grid item xs={2}  style={{display: "flex", justifyContent: "flex-end"}}>
                    <ButtonHandleCardPosition index={index} list={list} setList={setList} />
                    <IconButton size="medium" disabled={true}>
                        <SettingsIcon />
                    </IconButton>
                </Grid>
            </Grid>
            <Divider orientation="horizontal" style={{backgroundColor: "black"}} />
            <Grid className={classes.body} style={{overflowY: "hidden"}}>
                <ImageUploader
                    className={classes.input}
                    withIcon={true}
                    withPreview={false}
                    singleImage={true}
                    buttonText='Post Your Image'
                    onChange={(e) => setInput({open: true, file: e, complete: false})}
                    imgExtension={['.jpg', '.png']}
                    maxFileSize={5242880}
                />
            </Grid>
            <ModalSettingsPostImage
                open={input.open}
                setOpen={() => setInput({...input, complete: true})}
                setClose={() => setInput({...input, complete: true, file: undefined})}
                input={input}
                setInput={(el) => setInput(el)}
            />
            <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
        </Grid>
    );
};

export default WidgetImagePostImage;