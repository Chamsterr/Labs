import { useSelector } from 'react-redux';
import VacancyInfo from '../components/VacancyInfo';
import { rootReducer } from '../redux/store';


const VacancyInfoContainer = () => {
  const selectedVacancy = useSelector((state: rootReducer) => state.selectedVacancy);

  return <VacancyInfo vacancy={selectedVacancy} />;
};

export default VacancyInfoContainer;
