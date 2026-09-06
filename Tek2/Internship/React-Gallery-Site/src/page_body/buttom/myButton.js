import React from 'react'
import PropTypes from 'prop-types'
import Button from '@material-ui/core/Button';
import KeyboardArrowLeft from '@material-ui/icons/KeyboardArrowLeft';
import KeyboardArrowRight from '@material-ui/icons/KeyboardArrowRight';
import { Grid, Typography } from "@material-ui/core";

const MyButtom = ({current, total, nbrElement, cas, gotoend, next, prev, gotobegin}) => {
    return (
        <div>
            { cas === true && <br/> }
            <Grid container direction="row" justify="space-around" alignItems="center">
                {
                    cas === true &&
                    <Button onClick={() => gotobegin(current)}
                        variant="outlined"
                        disabled={current <= nbrElement}>
                            Début<KeyboardArrowLeft/>
                    </Button>
                }
                <Button size="small"
                    onClick={() => prev(current, nbrElement)}
                    variant="outlined"
                    disabled={current === 0 || total === nbrElement}>
                        <KeyboardArrowLeft/>prev
                </Button>
                {
                    cas === true && total !== nbrElement &&
                    <Typography variant="h5" component="h4">
                        {`${(Math.round(current / nbrElement + 1))} / ${Math.round(total / nbrElement)}`}
                    </Typography>
                }
                <Button size="small"
                    onClick={() => next(current, nbrElement, total)}
                    variant="outlined"
                    disabled={current + nbrElement === total || total === nbrElement}>
                        suiv<KeyboardArrowRight/>
                </Button>
                {
                    cas === true &&
                    <Button onClick={() => gotoend(nbrElement, total)}
                        variant="outlined"
                        disabled={current + nbrElement * 2 >= total}>
                            Fin<KeyboardArrowRight/>
                    </Button>
                }
            </Grid>
        </div>
    )
}

MyButtom.propTypes = {
    current: PropTypes.number.isRequired,
    total: PropTypes.number.isRequired,
    nbrElement: PropTypes.number.isRequired,
    cas: PropTypes.bool.isRequired,
    gotobegin: PropTypes.func.isRequired,
    next: PropTypes.func.isRequired,
    prev: PropTypes.func.isRequired,
    gotoend: PropTypes.func.isRequired
}

export default MyButtom;