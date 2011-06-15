import evas
import ecore
import edje
import elementary

VERSION

if __name__ == "__main__":
    logger.info("Editje " + VERSION)
    elementary.init()
    elementary.finger_size_set(15)
    elementary.policy_set(elementary.ELM_POLICY_QUIT,
                          elementary.ELM_POLICY_QUIT_LAST_WINDOW_CLOSED)

